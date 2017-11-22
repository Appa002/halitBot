//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_SUPPORTTASK_HPP
#define MYBOT_SUPPORTTASK_HPP

#include "Task.hpp"
#include "Validation.hpp"

class SupportTask: public Task {
public:
    Validation execute(std::vector<ShipIssueEnum>* issueVec);
};


#endif //MYBOT_SUPPORTTASK_HPP
