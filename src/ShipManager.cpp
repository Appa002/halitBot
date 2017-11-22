//
// Created by Albert on 22.11.2017.
//

#include "header/ShipManager.hpp"

Validation ShipManager::registerNewShips() {

    const hlt::Map map = hlt::in::get_map();

    for(auto ship : map.ships.at(DataCore::get()->playerId)){

        bool alreadyRegistered = false;
        for(auto registeredSmartShips : this->smartShips){
            if(ship.entity_id == registeredSmartShips.id){
                alreadyRegistered = true;
            }
        }

        if(!alreadyRegistered){
            SmartShip s = SmartShip(ship.entity_id);
            this->smartShips.push_back(s);
        }

    }

    return Validation();
}

Validation ShipManager::removeOldShips() {
    return Validation();
}

Validation ShipManager::updateTasks() {

    for(auto sShip : this->smartShips){
        sShip.setTask(new ConquerTask());
    }

    return Validation();
}

Validation ShipManager::executeTasks() {

    for(auto sShip : this->smartShips){
        sShip.doTask();
    }

    return Validation();
}
