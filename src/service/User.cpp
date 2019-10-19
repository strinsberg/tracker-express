#include "User.h"
#include <iostream>
#include <string>

using std::string;

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

