//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_TASK_HPP
#define MYBOT_TASK_HPP


#include <vector>
#include "Validation.hpp"
#include "ShipIssue.hpp"
#include "../hlt/hlt.hpp"

class Task {
public:
    hlt::Ship ship;
    virtual Validation execute(std::vector<ShipIssueEnum>* issueVec)= 0;
};


#endif //MYBOT_TASK_HPP
