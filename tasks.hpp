#ifndef TASKS_HPP
#define TASKS_HPP
#include "task.hpp"
#include <vector>
#include <string>

class tasks {
    private:
        std::vector<task> tasks;
    public:
        void add_task(task t);
        int num_tasks();
        std::string get_task_name(int t);
        int get_task_time(int t);
        bool get_task_complete(int t);
};

#endif