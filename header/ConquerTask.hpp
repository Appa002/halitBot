//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_CONQUERTASK_HPP
#define MYBOT_CONQUERTASK_HPP

#include "Task.hpp"
#include "Validation.hpp"
#include <hlt/planet.hpp>
#include <header/Utility.hpp>
#include <hlt/navigation.hpp>
#include "DataCore.hpp"


class ConquerTask : public Task{
public:
    Validation execute(std::vector<ShipIssueEnum>* issueVec);
};


#endif //MYBOT_CONQUERTASK_HPP
