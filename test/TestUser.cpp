#include <gtest/gtest.h>
#include "User.h"

TEST(TestUser, id_getter_Test) {
    User u(23, "name", "blurb", 2);
    EXPECT_EQ(23, u.Getid());
}



     /*  int Getid() { return id; }
        void Setid(int val) { id = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getblurb() { return blurb; }
        void Setblurb(string val) { blurb = val; }
        int GetpictureNum() { return pictureNum; }
        void SetpictureNum(int val) { pictureNum = val; }
*/
