#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using std::string;

class User
{
    public:
        User();
        User(int, string, string, int);
        virtual ~User();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getblurb() { return blurb; }
        void Setblurb(string val) { blurb = val; }
        int GetpictureNum() { return pictureNum; }
        void SetpictureNum(int val) { pictureNum = val; }

    protected:

    private:
        int id;
        string name;
        string blurb;
        int pictureNum;
};

#endif // USER_H
