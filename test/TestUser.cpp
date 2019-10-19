#include <gtest/gtest.h>
#include "User.h"
#include <string>

using std::string;

TEST(TestUser, id_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ(23, u.Getid());
}

TEST(TestUser, id_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.Setid(24);
    EXPECT_EQ(24, u.Getid());
}

TEST(TestUser, name_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ("name", u.Getname());
}

TEST(TestUser, name_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.Setname("changed");
    EXPECT_EQ("changed", u.Getname());
}

TEST(TestUser, blurb_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ("blurb", u.Getblurb());
}

TEST(TestUser, blurb_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.Setblurb("newBlurb");
    EXPECT_EQ("newBlurb", u.Getblurb());
}

TEST(TestUser, pictureNum_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ(2, u.GetpictureNum());
}

TEST(TestUser, pictureNum_setter_Test) {
    User u(23, "name", "blurb", 2);
    u.SetpictureNum(4);
    EXPECT_EQ(4, u.GetpictureNum());
}

