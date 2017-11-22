#include "hlt/hlt.hpp"
#include "hlt/navigation.hpp"
#include <cmath>
#include <vector>
#include "header/DataCore.hpp"
#include <header/Utility.hpp>
#include "header/ShipManager.hpp"


hlt::PlayerId playerId;

int support(std::vector<hlt::Move>* moves, hlt::Map map, hlt::Ship ship);
/*
int support(std::vector<hlt::Move>* moves, hlt::Map map, hlt::Ship ship){
    std::vector<hlt::Planet> excludes;
    hlt::Planet planet;

    for(size_t j = 0; j < map.planets.size(); j++){
        planet = findClosesPlanet(ship.location, map, excludes);
        if (!planet.owned)
            excludes.push_back(planet);
        else
            continue;
    }
    // Planet is closes owned planet
    
    if (ship.can_dock(planet)) {
        moves->push_back(hlt::Move::dock(ship.entity_id, planet.entity_id));
        return 0;
    }else{
        if(planet.docked_ships.size() >= planet.docking_spots){
          //  return conquer(moves, map, ship);
        }
        const hlt::possibly<hlt::Move> move =
        hlt::navigation::navigate_ship_to_dock(map, ship, planet, hlt::constants::MAX_SPEED / 2);

        if (move.second) {
            moves->push_back(move.first);
            return 0;
        }else{
            return 1;
        }
    }
}
*/

int main()
{
    hlt::Metadata metadata = hlt::initialize("Low budget Ava");

    DataCore::get()->playerId = metadata.player_id;

    hlt::PlayerId playerId =  metadata.player_id;
    const hlt::Map &initial_map = metadata .initial_map;

    // We now have 1 full minute to analyse the initial map.
    std::ostringstream initial_map_intelligence;
    initial_map_intelligence
        << "width: " << initial_map.map_width
        << "; height: " << initial_map.map_height
        << "; players: " << initial_map.ship_map.size()
        << "; my ships: " << initial_map.ship_map.at(playerId).size()
        << "; planets: " << initial_map.planets.size();
    hlt::Log::log(initial_map_intelligence.str());



    DataCore::get()->moves = new std::vector<hlt::Move>;


    while(true)
    {
        ShipManager::get()->removeOldShips();
        ShipManager::get()->registerNewShips();
        ShipManager::get()->updateTasks();
        ShipManager::get()->executeTasks();

        hlt::out::send_moves(*DataCore::get()->moves);

    }       
}
