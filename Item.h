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
    Item(std::string &name_Item, int quantity, Category* category) : name(name_Item), quantity(quantity), category(category) {}
    friend bool operator==(const Item& lhs, const Item& rhs);
};


#endif //LISTA_SPESA_LAB_PROG_ITEM_H
