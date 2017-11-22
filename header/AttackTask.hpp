//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_ATTACKTASK_HPP
#define MYBOT_ATTACKTASK_HPP

#include "Task.hpp"
#include "Validation.hpp"

class AttackTask : public Task {
public:
    Validation execute(std::vector<ShipIssueEnum>* issueVec);
};


#endif //MYBOT_ATTACKTASK_HPP
