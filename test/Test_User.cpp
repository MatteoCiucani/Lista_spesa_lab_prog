//
// Created by Matteo on 14/02/2023.
//
#include "gtest/gtest.h"
#include "../User.h"
#include "ObserverMock.h"

class Test_User: public ::testing::Test{
protected:
    void SetUp() override {
        user = new User("Matteo", "MatteCiuc");
    }
    User* user;
};

TEST_F(Test_User, TestGetUsername) {
    EXPECT_EQ("MatteCiuc", user->getUsername());
}

TEST_F(Test_User, TestAddList) {
    Listonic* list = new Listonic("Mangiare");
    Listonic* list2 = new Listonic("Latticini");
    user->addList(list);
    user->addList(list2);
    EXPECT_EQ(2, user->getNumLists());
}



