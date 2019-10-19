#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using std::string;

class User {
  public:
    User(int, string, string, int);
    virtual ~User();

    int getId() {
        return id;
    }
    void setId(int val) {
        id = val;
    }
    string getName() {
        return name;
    }
    void setName(string val) {
        name = val;
    }
    string getBlurb() {
        return blurb;
    }
    void setBlurb(string val) {
        blurb = val;
    }
    int getPictureNum() {
        return pictureNum;
    }
    void setPictureNum(int val) {
        pictureNum = val;
    }

  protected:

  private:
    int id;
    string name;
    string blurb;
    int pictureNum;
};

#endif // USER_H
