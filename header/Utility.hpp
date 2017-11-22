#include "hlt/hlt.hpp"


#ifndef MYBOT_UTILITY_HPP
#define MYBOT_UTILITY_HPP


inline hlt::Planet findClosesPlanet(hlt::Location location, hlt::Map map, std::vector<hlt::Planet> excludes){
    double closesDistance = 1000000;
    hlt::Planet closesPlanet = map.planets.at(0);

    for(auto planet : map.planets){
        double sqrDist = pow(planet.location.pos_x - location.pos_x, 2) + pow(planet.location.pos_y - location.pos_y, 2);

        if(sqrDist < closesDistance){
            bool inExclude = false;
            for(auto exclude : excludes){
                if(exclude.entity_id == planet.entity_id){
                    inExclude = true;
                    continue;
                }
            }

            if(!inExclude){
                closesDistance = sqrDist;
                closesPlanet = planet;
            }

        }

    }
    return closesPlanet;
}



#endif //MYBOT_UTILITY_HPP
