#include "User.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

using std::string;

User::User(int id) : id(id),
    name(""), blurb(""), pictureNum(0) {}

User::User(int id, string name, string blurb, int pictureNum):id(id),
    name(name), blurb(blurb), pictureNum(pictureNum) {}

User::~User() {
    //dtor
}

int User::getId() {
    return id;
}

void User::setId(int val) {
    id = val;
}

string User::getName() {
    return name;
}

void User::setName(string val) {
    name = val;
}

string User::getBlurb() {
    return blurb;
}

void User::setBlurb(string val) {
    blurb = val;
}

int User::getPictureNum() {
    return pictureNum;
}

void User::setPictureNum(int val) {
    pictureNum = val;
}

void User::update(std::string json) {
    auto data = nlohmann::json::parse(json);

    if (data.find("name") != data.end())
        name = data["name"];
    if (data.find("blurb") != data.end())
        blurb = data["blurb"];
    if (data.find("pic") != data.end())
        pictureNum = data["pic"];
}

nlohmann::json User::toJson() {
    nlohmann::json data;

    data["id"] = id;
    data["name"] = name;
    data["blurb"] = blurb;
    data["pic"] = pictureNum;

    return data;
}
