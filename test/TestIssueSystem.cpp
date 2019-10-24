#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include <vector>
#include "gtest/gtest.h"


TEST(TestIssueSystem, getIssues_CreateIssues_test) {
    IssueSystem IS;
    //create an issue that with id = 1
    EXPECT_EQ(1, IS.createIssue());
    EXPECT_EQ(2, IS.createIssue());
    EXPECT_EQ(3, IS.createIssue());
}

TEST(TestIssueSystem, getUsers_CreateUser_test) {
    IssueSystem IS;
    EXPECT_EQ(1, IS.createUser());
    EXPECT_EQ(2, IS.createUser());
    EXPECT_EQ(3, IS.createUser());
    //EXPECT_EQ(IS.users, IS.getUsers());
}

TEST(TestIssueSystem, getComments_CreateComments_test) {
    IssueSystem IS;
    EXPECT_EQ(1, IS.createComment());
    EXPECT_EQ(2, IS.createComment());
    EXPECT_EQ(3, IS.createComment());
}

TEST(TestIssueSystem, getIssue_by_Id) {
    //create a specific issue in the vector and return it
    //Can't do this yet, no id in Issue Class
}

TEST(TestIssueSystem, getUser_by_Id) {
    //create a specific user in the vector and return it
    IssueSystem IS;
    int testId = IS.createUser();
    EXPECT_EQ(testId, IS.getUser(testId).getId());
}

TEST(TestIssueSystem, getComment_by_Id) {
    //create a specific comment then return it
    IssueSystem IS;
    int testId = IS.createComment();
    EXPECT_EQ(testId, IS.getComment(testId).getCommentId());
}


