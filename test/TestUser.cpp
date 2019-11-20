#include "User.h"
#include <gtest/gtest.h>
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

TEST(TestUser, update_all) {
    User user(23, "name", "blurb", 2);

    nlohmann::json data = {
        {"name", "steve"},
        {"blurb", "something about steve"},
        {"pic", 5},
    };

    user.update(data.dump());

    EXPECT_EQ("steve", user.getName());
    EXPECT_EQ("something about steve", user.getBlurb());
    EXPECT_EQ(5, user.getPictureNum());
}

TEST(TestUser, to_json) {
    User user(23, "name", "blurb", 2);

    auto data = user.toJson();

    EXPECT_EQ(23, data["id"]);
    EXPECT_EQ("name", data["name"]);
    EXPECT_EQ("blurb", data["blurb"]);
    EXPECT_EQ(2, data["pic"]);
}
