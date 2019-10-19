#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using std::string;

/**
 * Header file for the User class.
 * @author Mathew Richards
 * @date 2019-10
 */
class User {
 public:
    /**
     * Creates a user object.
     * @param id The user's id number
     * @param name The user's name
     * @param blurb The user's profile blurb
     * @param pictureNum The user's profile picture choice
    */
    User(int id, string name, string blurb, int pictureNum);
    virtual ~User();

    /**
     * Getter method for the id.
     * @return id The user's id number
    */
    int getId();

    /**
     * Setter method for the id.
     * @param val The new value for the user id
     */
    void setId(int val);

    /**
     * Getter method for user name
     * @return name The user's name
     */
    string getName();

    /**
     * Setter method for user name
     * @param val The new name for the user
     */
    void setName(string val);

    /**
     * Getter for the user's blurb
     * @return blurb The user's blurb
     */
    string getBlurb();

    /**
     * Setter method for the blurb
     * @param val The new blurb for the user
     */
    void setBlurb(string val);

    /**
     * Getter method for the pictureNum
     * @return pictureNum The id that will correspond to a user photo
     */
    int getPictureNum();

    /**
     * Setter method for the pictureNum
     * @param val The id for the new user picture
     */
    void setPictureNum(int val);

 protected:
    //prevent style error
 private:
    int id;
    string name;
    string blurb;
    int pictureNum;
};

#endif // USER_H