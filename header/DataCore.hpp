//
// Created by Albert on 22.11.2017.
//

#ifndef MYBOT_DATACORE_HPP
#define MYBOT_DATACORE_HPP

#include "Singleton.hpp"
#include "../hlt/hlt.hpp"

class DataCore : public Singleton<DataCore> {
public:
    ~DataCore(){
        delete moves;
    }

    std::vector<hlt::Move>* moves;
    hlt::PlayerId playerId;
};


#endif //MYBOT_DATACORE_HPP
