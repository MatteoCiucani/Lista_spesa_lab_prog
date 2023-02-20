//
// Created by Matteo on 13/02/2023.
//

#include "Item.h"
bool operator==(const Item &lhs, const Item &rhs){
    if (lhs.name == rhs.name && lhs.quantity == rhs.quantity && lhs.category->name == rhs.category->name){
        return true;
    }
    else
        return false;
}
