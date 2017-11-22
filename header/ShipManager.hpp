#ifndef MYBOT_SHIPMANAGER_HPP
#define MYBOT_SHIPMANAGER_HPP

#include <vector>
#include "SmartShip.hpp"
#include "Validation.hpp"
#include "Singleton.hpp"
#include "DataCore.hpp"
#include <header/ConquerTask.hpp>


class ShipManager : public Singleton<ShipManager> {
private:
    std::vector<SmartShip> smartShips;
public:
    Validation removeOldShips();
    Validation registerNewShips();
    Validation updateTasks();
    Validation executeTasks();
};


#endif //MYBOT_SHIPMANAGER_HPP
