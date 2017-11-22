//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_ISSUEENUM_HPP
#define MYBOT_ISSUEENUM_HPP

enum ShipIssueEnum{
    PlanetHasBeenCaptured, // Thrown When the target planet has been captured by the enemy
    HaveBeenEngagedInCombat, // Thrown when ship was engaged in combat
    WillengagedInCombat, // Thrown when ship has to engaged in combat
    planetHasBeenFreed // Thrown when the target planet has been freed (eg. my ships have taken control of planet)
};

#endif //MYBOT_ISSUEENUM_HPP
