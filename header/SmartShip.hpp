//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_SMARTSHIP_HPP
#define MYBOT_SMARTSHIP_HPP

#include <vector>
#include "ShipIssue.hpp"
#include "Task.hpp"
#include "Validation.hpp"
#include "../hlt/hlt.hpp"


class SmartShip {
private:
    Task* task;
public:
    const hlt::EntityId id;
    std::vector<ShipIssueEnum> issues;

    explicit SmartShip(hlt::EntityId id);
    SmartShip(hlt::EntityId id, Task *task);
    Validation doTask();
    Validation setTask(Task *task);
    Task * getTask();
};


#endif //MYBOT_SMARTSHIP_HPP
