//
// Created by Matteo on 15/02/2023.
//
#include "gtest/gtest.h"
#include "../Listonic.h"

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


