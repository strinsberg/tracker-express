#ifndef COMMENT_H
#define COMMENT_H

#include<string>
using std::string;
class Comment{
 public:
     /**
     * @brief Default constructor for Comment class
     * @param The ID of the comment, sets the commentID variable
     */
     Comment(int);
     /**
     * @brief Setter for the Issue ID
     * @param issue_id, the Issue ID to set
     */
     void setIssueID(int);
     /**
     * @brief Setter for the User ID
     * @param user_id, the User ID to set
     */
     void setUserID(int);
     /**
     * @brief Setter for the comment text
     * @param comment, The text of the comment
     */
     void setCommentText(string);
     /**
     * @brief Setter for Comment ID
     * @param comment_id, the Comment ID to set
     */
     int getCommentID();
     /**
     * @brief Getter for the Issue ID
     * @return issueID, The issueID variable
     */
     int getIssueID();
     /**
     * @brief Getter for the User ID
     * @return userID, the UserID
     */
     int getUserID();
     /**
     * @brief Getter for the Comment text
     * @return The Comment string
     */
     string getCommentText();
     /**
     * @brief Destructor for Comment class.
     */
     ~Comment();

 private:
    int commentID;
    int issueID;
    int userID;
    string text;
};

#endif // COMMENT_H
