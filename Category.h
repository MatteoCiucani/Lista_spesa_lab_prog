//
// Created by Matteo on 13/02/2023.
//

#ifndef LISTA_SPESA_LAB_PROG_CATEGORY_H
#define LISTA_SPESA_LAB_PROG_CATEGORY_H

#include <string>

class Category {
public:
    std::string name;
    Category(const std::string &name_category) : name(name_category) {}
    friend bool operator==(const Category& lhs, const Category& rhs);
};


#endif //LISTA_SPESA_LAB_PROG_CATEGORY_H
