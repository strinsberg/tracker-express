#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using std::string;

class User {
 public:
    User(int, string, string, int);
    virtual ~User();

    int getId();
    void setId(int val);
    string getName();
    void setName(string val);
    string getBlurb();
    void setBlurb(string val);
    int getPictureNum();
    void setPictureNum(int val);

 protected:

 private:
    int id;
    string name;
    string blurb;
    int pictureNum;
};

#endif // USER_H
