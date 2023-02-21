//
// Created by Matteo on 13/02/2023.
//

#ifndef LISTA_SPESA_LAB_PROG_USER_H
#define LISTA_SPESA_LAB_PROG_USER_H

#include "ListonicObserver.h"
#include "Listonic.h"

class User : public ListonicObserver {
public:
    User(std::string name_User, std::string username) : name(name_User), username(username) {}

    void addList(Listonic* list);

    void onListUpdate(Listonic* list) override{
        std::cout << "L'utente: " << name << " aggiorna la lista " << list->name << ":" << std::endl;
        for (auto item : list->getItems()) {
            std::cout << " - " << item->name << " (" << item->quantity << ") [" << item->category->name << "]" << std::endl;
        }
    }

    std::string getUsername() const;

    int getNumLists() const;

private:
    std::string name;
    std::vector<Listonic*> lists;
    std::string username;
};



#endif //LISTA_SPESA_LAB_PROG_USER_H
