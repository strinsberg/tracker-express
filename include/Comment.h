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
     explicit Comment(int);
     /**
     * @brief Setter for the Issue ID
     * @param issue_id, the Issue ID to set
     */
     void setIssueId(int);
     /**
     * @brief Setter for the User ID
     * @param user_id, the User ID to set
     */
     void setUserId(int);
     /**
     * @brief Setter for the comment text
     * @param comment, The text of the comment
     */
     void setCommentText(string);
     /**
     * @brief Setter for Comment ID
     * @param comment_id, the Comment ID to set
     */
     int getCommentId();
     /**
     * @brief Getter for the Issue ID
     * @return issueID, The issueID variable
     */
     int getIssueId();
     /**
     * @brief Getter for the User ID
     * @return userID, the UserID
     */
     int getUserId();
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
    int commentId;
    int issueId;
    int userId;
    string text;
};

#endif // COMMENT_H
