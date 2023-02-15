//
// Created by Matteo on 14/02/2023.
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
    EXPECT_EQ(list.getItems().size(), 4);
    EXPECT_EQ(list.getItems()[3], "Mela");

    EXPECT_EQ(list.getCategories()[0], "Frutta");
}

TEST_F(test_Listonic, RemoveItem) {
    list.removeItem(1);
    EXPECT_EQ(list.getItems().size(), 2);
    EXPECT_EQ(list.getItems()[1], "Pane");

    EXPECT_EQ(list.getCategories()[0], "Mangiare");
}

TEST_F(test_Listonic, SetQuantity) {
    list.setQuantity(0, 3);
    EXPECT_EQ(list.getItems().size(), 3);
    EXPECT_EQ(list.getItems()[0], "Latte");

    EXPECT_EQ(list.getCategories()[0], "Mangiare");
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

TEST_F(test_Listonic, GetName) {
    EXPECT_EQ(list.getName(), "Test List");
}

TEST_F(test_Listonic, GetItems) {
    EXPECT_EQ(list.getItems().size(), 3);
    EXPECT_EQ(list.getItems()[0], "latte");
    EXPECT_EQ(list.getItems()[1], "Uova");
    EXPECT_EQ(list.getItems()[2], "Pane");
}


TEST_F(test_Listonic, GetCategories) {
    EXPECT_EQ(list.getCategories().size(), 2);
    EXPECT_EQ(list.getCategories()[0], "Mangiare");
    EXPECT_EQ(list.getCategories()[0], "Latticini");

}