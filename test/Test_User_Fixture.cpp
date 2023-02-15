//
// Created by Matteo on 15/02/2023.
//
#include "gtest/gtest.h"
#include "../User.h"

class Test_User: public ::testing::Test{
protected:
    void SetUp() override {
        user = new User("Matteo", "MatteCiuc");
    }

    void TearDown() override {
        delete user;
    }

    User* user;
};

