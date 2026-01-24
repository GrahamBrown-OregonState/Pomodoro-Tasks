#include "tasks.hpp"

void tasks::add_task(task t) {
    this->tasks.push_back(t);
}

int tasks::num_tasks() {
    return this->tasks.size();
}

std::string tasks::get_task_name(int t) {
    return this->tasks.at(t).name;
}

int tasks::get_task_time(int t) {
    return this->tasks.at(t).minutes_spent;
}

bool tasks::get_task_complete(int t) {
    return this->tasks.at(t).complete;
}