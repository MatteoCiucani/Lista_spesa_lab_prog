//
// Created by Matteo on 13/02/2023.
//

#include "Category.h"
bool operator==(const Category &lhs, const Category &rhs) {
    if (lhs.name == rhs.name){
        return true;
    }
    return false;
}
