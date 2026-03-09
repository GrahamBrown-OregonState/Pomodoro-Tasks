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
    std::cout << "1. Work on task" << std::endl;
    std::cout << "2. Mark task as complete" << std::endl;
    std::cout << "3. Reorder tasks" << std::endl;
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
