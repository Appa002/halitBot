//
// Created by Albert on 22.11.2017.
//

#include "header/ConquerTask.hpp"

Validation ConquerTask::execute(std::vector<ShipIssueEnum> *) {

    hlt::Map map = hlt::in::get_map();

    std::vector<hlt::Planet> excludes;
    hlt::Planet planet;

    for(size_t j = 0; j < map.planets.size(); j++){
        planet = findClosesPlanet(ship.location, map, excludes);
        if (planet.owned)
            excludes.push_back(planet);
        else
            continue;

    }
    // Planet is closes not owned planet

    if (ship.can_dock(planet)) {
        DataCore::get()->moves->push_back(hlt::Move::dock(ship.entity_id, planet.entity_id));
        return Validation();
    }else{
        const hlt::possibly<hlt::Move> move =
                hlt::navigation::navigate_ship_to_dock(map, ship, planet, hlt::constants::MAX_SPEED / 2);

        if (move.second) {
            DataCore::get()->moves->push_back(move.first);
            return Validation();
        }else{
            return Validation("Move is impossible");
        }
    }
}
