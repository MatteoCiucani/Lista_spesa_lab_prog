//
// Created by Matteo on 13/02/2023.
//

#ifndef LISTA_SPESA_LAB_PROG_LISTONICOBSERVER_H
#define LISTA_SPESA_LAB_PROG_LISTONICOBSERVER_H


class Listonic;

class ListonicObserver {
public:
    virtual void onListUpdate(Listonic* list) = 0;
};

#endif //LISTA_SPESA_LAB_PROG_LISTONICOBSERVER_H
