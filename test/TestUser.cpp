#include "gtest/gtest.h"
#include "User.h"
#include <iostream>
#include <string>

using std::string;

TEST(TestUser, id_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ(23, u.getId());
}

TEST(TestUser, id_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.setId(24);
    EXPECT_EQ(24, u.getId());
}

TEST(TestUser, name_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ("name", u.getName());
}

TEST(TestUser, name_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.setName("changed");
    EXPECT_EQ("changed", u.getName());
}

TEST(TestUser, blurb_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ("blurb", u.getBlurb());
}

TEST(TestUser, blurb_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.setBlurb("newBlurb");
    EXPECT_EQ("newBlurb", u.getBlurb());
}

TEST(TestUser, pictureNum_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ(2, u.getPictureNum());
}

TEST(TestUser, pictureNum_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.setPictureNum(4);
    EXPECT_EQ(4, u.getPictureNum());
}

