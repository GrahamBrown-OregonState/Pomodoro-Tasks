#include "tasks.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include "external/tabulate/include/tabulate/table.hpp"

void outputTasks(tasks t) {
    using namespace tabulate;

    Table t_table; // task table

    std::cout << "Current Tasks:" << std::endl;
    t_table.add_row({"Name", "Minutes Worked On", "Complete?"});

    // add all tasks to tabulate table
    for (int i = 0; i < t.num_tasks(); i++) {
        t_table.add_row({t.get_task_name(i), 
            std::to_string(t.get_task_time(i)),
            t.get_task_complete(i) ? "✅" : "❌"});
    }

    // format task table
    t_table[0].format()
    .font_style({FontStyle::bold})
    .font_align(FontAlign::center);

    std::cout << t_table << std::endl;
}

void outputMenu() {
    std::cout << "Welcome! Select an option:" << std::endl;
    std::cout << "1. Add task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Work on task" << std::endl;
    std::cout << "4. Mark task as complete" << std::endl;
    std::cout << "5. Reorder tasks" << std::endl;
}

int getMenuOption() {
    int option;
    std::cin >> option;
    return option;
}

void displayTime(int hours, int minutes, int seconds) {
    std::cout << hours << ":"
        << minutes << ":" << seconds
}

void beginTask(task t) {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    auto start_time = std::chrono::steady_clock::now();

    while (true) {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();

        hours = elapsed_time / 3600;
        minutes = (elapsed_time % 3600) / 60;
        seconds = elapsed_time % 60;

        displayTime(hours, minutes, seconds);
        sleep(1);
    }
}

void addTask(tasks &t) {
    std::string name;
    std::cout << "Enter task name: ";
    std::cin >> name;
    t.add_task(task(name));
}

void markTaskComplete(tasks &t) {
    int index;
    std::cout << "Enter task index to mark as complete: ";
    std::cin >> index;
    if (index < 0 || index >= t.num_tasks()) {
        std::cout << "Invalid task index." << std::endl;
        return;
    }
    t.mark_task_complete(index);
}

void reorderTasks(tasks &t) {
    std::string task1, task2;
    std::cout << "Enter the names of the two tasks to swap: ";
    std::cin >> task1 >> task2;
    int index1 = t.get_task_index(task1);
    int index2 = t.get_task_index(task2);
    if (index1 == -1 || index2 == -1) {
        std::cout << "One or both task names not found." << std::endl;
        return;
    }
    t.swap_tasks(index1, index2);
}

int main() {
    tasks t;

    while (true) {
        outputMenu();
        int option = getMenuOption();

        switch (option) {
            case 1:
                addTask(t);
                break;
            case 2:
                outputTasks(t);
                break;
            case 3: {
                int index;
                std::cout << "Enter task index to work on: ";
                std::cin >> index;
                if (index < 0 || index >= t.num_tasks()) {
                    std::cout << "Invalid task index." << std::endl;
                    break;
                }
                beginTask(t.get_task(index));
                break;
            }
            case 4:
                markTaskComplete(t);
                break;
            case 5:
                // reorder tasks
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}

