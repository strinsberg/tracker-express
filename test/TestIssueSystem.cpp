#include "gtest/gtest.h"
#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include <vector>

TEST(TestIssueSystem, getIssues_CreateIssues_test) {
    IssueSystem IS;
    EXPECT_EQ(1, IS.createIssue());
    //EXPECT_EQ(, IS.getIssues());
}

TEST(TestIssueSystem, getUser_CreateUser_test) {
    IssueSystem IS;
    EXPECT_EQ(-1, IS.createUser());
    //EXPECT_EQ(, IS.getUsers());
}

TEST(TestIssueSystem, getIssue_by_ID) {
    //create a specific issue in the vector and return it
    //Can't do this yet, no id in Issue Class
}

TEST(TestIssueSystem, getUser_by_ID) {
    //create a specific user in the vector and return it

}


/*
  std::vector<Comment>& getComments();

  Comment& getComment();

  int CreateComment();
  */


