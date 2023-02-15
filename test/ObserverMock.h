//
// Created by Matteo on 14/02/2023.
//

#ifndef LISTA_SPESA_LAB_PROG_OBSERVERMOCK_H
#define LISTA_SPESA_LAB_PROG_OBSERVERMOCK_H

#include "../ListonicObserver.h"

class ObserverMock : public ListonicObserver {
public:
    ObserverMock() {}
    ~ObserverMock() {}
    void onListUpdate(Listonic* list) override {
        this->list = list;
    }
    Listonic* getList() {
        return list;
    }
private:
    Listonic* list = nullptr;
};

#endif //LISTA_SPESA_LAB_PROG_OBSERVERMOCK_H
