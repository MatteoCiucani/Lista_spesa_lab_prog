#include <iostream>
#include "ListonicObserver.h"
#include "Listonic.h"
#include "Item.h"
#include "User.h"
#include "Category.h"

int main() {
    std::string lista("lista1");
    Listonic* list = new Listonic(lista);

    // creazione di una categoria
    Category* fruitCategory = new Category("Frutta");

    // aggiunta di un elemento alla lista
    list->addItem("Mela", 5, "Frutta");

    // creazione di  utenti
    User* user = new User("Matteo", "MatteCiuc");

    User* user1 = new User("Alessandro", "Ale00");

    User* user2 = new User("Elisa", "Eli68");

    // l'utente aggiunge la lista alla propria collezione
    user->addList(list);

    // aggiornamento della quantità di un elemento nella lista
    list->setQuantity(0, 3);
    list->addItem("banana", 3, "Frutta");

    // rimozione di un elemento dalla lista
    list->removeItem(1);

    // creazione di un'altra lista
    std::string lista1("Lista2");
    Listonic* list2 = new Listonic(lista1);

    // l'utente aggiunge anche questa lista alla propria collezione
    user1->addList(list2);

    // aggiunta di elementi alla seconda lista

    list2->addItem("formaggio", 5, "latticini");

    // rimozione dell'utente dalla prima lista
    list->removeObserver(user);

    std::string lista3("Lista3");
    Listonic* list3 = new Listonic(lista3);

    // l'utente aggiunge un elemento alla seconda lista
    list2->addItem("latte", 1, "latticini");

    user2->addList(list);
    list->addItem("arancia", 2, "Frutta");
    list->addItem("mozzarella", 3, "latticini");
    list2->addItem("carta igenica", 3, "sanitari");

    return 0;
}
