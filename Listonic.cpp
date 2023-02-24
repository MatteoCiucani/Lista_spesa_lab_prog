//
// Created by Matteo on 13/02/2023.
//

#include "Listonic.h"

void Listonic::addItem(std::string name, int quantity, std::string categoryName) {
    Category* category = getCategory(categoryName);
    Item* item = new Item(name, quantity, category);
    items.push_back(item);
    notifyObservers();
}

void Listonic::removeItem(int index) {
    items.erase(items.begin() + index);
    notifyObservers();
}

void Listonic::setQuantity(int index, int quantity) {
    items[index]->quantity = quantity;
    notifyObservers();
}

void Listonic::addObserver(ListonicObserver *observer) {
    observers.push_back(observer);

}

void Listonic::removeObserver(ListonicObserver *observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Listonic::notifyObservers() {
    for (auto observer : observers) {
        observer->onListUpdate(this);
    }
}

const std::string &Listonic::getName() const {
    return name;
}

















