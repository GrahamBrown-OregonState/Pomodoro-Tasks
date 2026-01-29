#include "tasks.hpp"
#include <iostream>
#include <string>
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
