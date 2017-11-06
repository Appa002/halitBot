#include "hlt/hlt.hpp"
#include "hlt/navigation.hpp"
#include <cmath>
#include <vector>

int conquer(std::vector<hlt::Move>* moves, hlt::Map map, hlt::Ship ship);    
int support(std::vector<hlt::Move>* moves, hlt::Map map, hlt::Ship ship);
hlt::Planet findClosesPlanet(hlt::Location location, hlt::Map map, std::vector<hlt::Planet> excludes);    


int conquer(std::vector<hlt::Move>* moves, hlt::Map map, hlt::Ship ship){
    std::vector<hlt::Planet> excludes;
    hlt::Planet planet;

    for(size_t j = 0; j < map.planets.size(); j++){
        planet = findClosesPlanet(ship.location, map, excludes);
        if (planet.owned)
            excludes.push_back(planet);
        else
            continue;
    }
    hlt::Log::log(std::to_string(planet.entity_id));        
    // Planet is closes not owned planet

    if (ship.can_dock(planet)) {
        moves->push_back(hlt::Move::dock(ship.entity_id, planet.entity_id));
        return 0;
    }else{
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
    hlt::Log::log(std::to_string(planet.entity_id));            
    // Planet is closes owned planet

    if (ship.can_dock(planet)) {
        moves->push_back(hlt::Move::dock(ship.entity_id, planet.entity_id));
        return 0;
    }else{
        if(planet.docked_ships.size() >= planet.docking_spots){
            return conquer(moves, map, ship);
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


hlt::Planet findClosesPlanet(hlt::Location location, hlt::Map map, std::vector<hlt::Planet> excludes){
    long closesDistance = 1000000;
    hlt::Planet closesPlanet = map.planets.at(0);

    for(auto planet : map.planets){
        long dist = pow(planet.location.pos_x - location.pos_x, 2) + pow(planet.location.pos_y - location.pos_y, 2);
        if(dist < closesDistance){
            for(auto exclude : excludes){
                if(exclude.entity_id == planet.entity_id){
                    goto end;
                }
            }
            closesDistance = dist;
            closesPlanet = planet;
        }
        end:
        int hi = 0;
        hi++;
    }
    return closesPlanet;
}


int main()
{
    const hlt::Metadata metadata = hlt::initialize("Low budget Ava");
    const hlt::PlayerId player_id = metadata.player_id;

    const hlt::Map &initial_map = metadata.initial_map;

    // We now have 1 full minute to analyse the initial map.
    std::ostringstream initial_map_intelligence;
    initial_map_intelligence
        << "width: " << initial_map.map_width
        << "; height: " << initial_map.map_height
        << "; players: " << initial_map.ship_map.size()
        << "; my ships: " << initial_map.ship_map.at(player_id).size()
        << "; planets: " << initial_map.planets.size();
    hlt::Log::log(initial_map_intelligence.str());

    std::vector<hlt::Move> moves;
    for (;;)
    {
        size_t i = 0;
        moves.clear();
        const hlt::Map map = hlt::in::get_map();

        for(auto ship : map.ships.at(player_id)){
            if(i % 2 == 0){
                conquer(&moves, map, ship);
            }else{
                support(&moves, map, ship);
            }

            i++;
        }
        hlt::out::send_moves(moves);        
    }       
}