//
// Created by Matteo on 13/02/2023.
//

#ifndef LISTA_SPESA_LAB_PROG_ITEM_H
#define LISTA_SPESA_LAB_PROG_ITEM_H

#include "Category.h"
#include <string>
class Item {
public:
    std::string name;
    int quantity;
    Category* category;
    Item(std::string name, int quantity, Category* category) : name(name), quantity(quantity), category(category) {}





};


#endif //LISTA_SPESA_LAB_PROG_ITEM_H
