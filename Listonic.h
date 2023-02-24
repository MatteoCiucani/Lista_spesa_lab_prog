//
// Created by Matteo on 13/02/2023.
//

#ifndef LISTA_SPESA_LAB_PROG_LISTONIC_H
#define LISTA_SPESA_LAB_PROG_LISTONIC_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Category.h"
#include "Item.h"
#include "ListonicObserver.h"
#include <algorithm>

class Listonic {
public:
    explicit Listonic(const std::string &name_Listonic) : name(name_Listonic) {}

    void addItem(std::string name, int quantity, std::string categoryName);

    void removeItem(int index);

    void setQuantity(int index, int quantity);

    const std::string &getName() const;

    void addObserver(ListonicObserver* observer);

    void removeObserver(ListonicObserver* observer);

    void notifyObservers();

    std::vector<Item*> getItems() {
        return items;
    };
    std::map<std::string, Category*> getCategories() {
        return categories;
    };


    std::string name;
private:

    std::vector<Item*> items;
    std::map<std::string, Category*> categories;
    std::vector<ListonicObserver*> observers;

public:

    Category* getCategory(std::string &categoryName){
        auto it = categories.find(categoryName);
        if (it != categories.end()) {
            return it->second;
        }
        Category* category = new Category(categoryName);
        categories[categoryName] = category;
        return category;
    }
};


#endif //LISTA_SPESA_LAB_PROG_LISTONIC_H
