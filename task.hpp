#ifndef TASK_HPP
#define TASK_HPP
#include <string>

struct task {
    std::string name;
    int minutes_spent;
    bool complete;
};

#endif