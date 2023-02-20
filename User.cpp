//
// Created by Matteo on 13/02/2023.
//

#include "User.h"

void User::addList(Listonic *list) {
    list->addObserver(this);
    lists.push_back(list);
}

std::string User::getUsername() const {
    return std::string(username);
}

int User::getNumLists() const {
    return lists.size();
}




