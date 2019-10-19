#include "User.h"
#include <iostream>
#include <string>

using std::string;

User::User(int id, string name, string blurb, int pictureNum):id(id),
    name(name), blurb(blurb), pictureNum(pictureNum) {}

User::~User() {
    //dtor
}

