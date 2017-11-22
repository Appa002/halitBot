//
// Created by Albert on 22.11.2017.
//

#include <string>

#ifndef MYBOT_VALIDATION_HPP
#define MYBOT_VALIDATION_HPP


class Validation {
public:
    Validation() : what(""), error(false) {}
    Validation(const std::string &what) : what(what), error(true) {}

    std::string what;
    bool error;
};


#endif //MYBOT_VALIDATION_HPP
