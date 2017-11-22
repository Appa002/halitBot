//
// Created by Albert on 22.11.2017.
//

#include "header/SmartShip.hpp"

SmartShip::SmartShip(hlt::EntityId id, Task *task) : id(id), task(task) {

}

SmartShip::SmartShip(const hlt::EntityId id) : id(id) {

}

Validation SmartShip::doTask() {
    return Validation();
}

Validation SmartShip::setTask(Task *task) {
    return Validation();
}

Task * SmartShip::getTask() {
    return this->task;
}
