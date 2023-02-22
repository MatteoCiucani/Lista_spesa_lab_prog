//
// Created by Matteo on 15/02/2023.
//

#include "gtest/gtest.h"
#include "../Listonic.h"
#include "ObserverMock.h"


class test_Listonic: public ::testing::Test  {
protected:
    void SetUp() override {
        list.addItem("Latte", 2, "Mangiare");
        list.addItem("Uova", 12, "Mangiare");
        list.addItem("Pane", 1, "Mangiare");
    }
    void TearDown() override {
        list = Listonic("Test List");
    }
    Listonic list = Listonic("Test List");
};



TEST_F(test_Listonic, AddItem) {
    list.addItem("Mela", 3, "Frutta");
    ASSERT_EQ(list.getItems().size(), 4);
    Category cat_Fruit = Category("Frutta");
    std::string name_product = "Mela";
    Item item_mela = Item(name_product, 3, &cat_Fruit);
    ASSERT_EQ(*(list.getItems()[3]), item_mela);
    ASSERT_EQ(*(list.getCategories()["Frutta"]), cat_Fruit);
}


TEST_F(test_Listonic, RemoveItem) {
    list.removeItem(1);
    ASSERT_EQ(list.getItems().size(), 2);
    Category cat_pointer = Category("Mangiare");
    std::string name_product = "Pane";
    Item pane = Item(name_product, 1, &cat_pointer);
    ASSERT_EQ(*list.getItems()[1], pane);
    ASSERT_EQ(*(list.getCategories()["Mangiare"]), cat_pointer);
}

TEST_F(test_Listonic, SetQuantity) {
    list.setQuantity(0, 3);
    ASSERT_EQ(list.getItems().size(), 3);
    Category cat_pointer = Category("Mangiare");
    std::string name_product = "Latte";
    Item latte = Item(name_product, 3, &cat_pointer);
    ASSERT_EQ(*list.getItems()[0], latte);
    ASSERT_EQ(*(list.getCategories()["Mangiare"]), cat_pointer);
}


TEST_F(test_Listonic, AddObserver) {
    ObserverMock* observer = new ObserverMock();
    list.addObserver(observer);
    list.addItem("Mela", 3, "Frutta");
    EXPECT_EQ(observer->getList(), &list);
    delete observer;
}

TEST_F(test_Listonic, RemoveObserver) {
    ObserverMock* observer = new ObserverMock();
    list.addObserver(observer);
    list.removeItem(1);
    list.removeObserver(observer);
    list.addItem("Mela", 3, "Frutta");
    EXPECT_EQ(observer->getList(), &list);
    delete observer;
}



