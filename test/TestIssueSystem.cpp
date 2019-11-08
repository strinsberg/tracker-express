#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include <vector>
#include <stdexcept>
#include <nlohmann/json.hpp>
#include "gtest/gtest.h"


TEST(TestIssueSystem, CreateIssues_test) {
    IssueSystem iss;

    EXPECT_EQ(1, iss.createIssue());
    EXPECT_EQ(2, iss.createIssue());
    EXPECT_EQ(3, iss.createIssue());
}

TEST(TestIssueSystem, CreateUser_test) {
    IssueSystem iss;

    EXPECT_EQ(1, iss.createUser());
    EXPECT_EQ(2, iss.createUser());
    EXPECT_EQ(3, iss.createUser());
}

TEST(TestIssueSystem, CreateComments_test) {
    IssueSystem iss;

    EXPECT_EQ(1, iss.createComment());
    EXPECT_EQ(2, iss.createComment());
    EXPECT_EQ(3, iss.createComment());
}

TEST(TestIssueSystem, createIssue_json) {
    IssueSystem system;
    const char* tempJson = "{\"title\" : \"meow\", \"description\" : \"description\", \"assignee\" : 18, \"creator\" : 12, \"priority\" : 132}";
    Issue& iss = system.createIssue(tempJson);
    EXPECT_EQ("meow", iss.getTitle());
}

TEST(TestIssueSystem, getIssue_by_Id) {
    IssueSystem iss;

    int testId = iss.createIssue();
    EXPECT_EQ(testId, iss.getIssue(testId).getId());
}

TEST(TestIssueSystem, getUser_by_Id) {
    IssueSystem iss;
    int testId = iss.createUser();

    EXPECT_EQ(testId, iss.getUser(testId).getId());
}

TEST(TestIssueSystem, getComment_by_Id) {
    IssueSystem iss;
    int testId = iss.createComment();

    EXPECT_EQ(testId, iss.getComment(testId).getId());
}

TEST(TestIssueSystem, getIssues) {
    IssueSystem iss;
    vector<Issue> tempIssues;
    iss.createIssue();
    tempIssues = iss.getIssues();
    //don't compare issue directly, compare ID??
    EXPECT_EQ(tempIssues[0].getId(), iss.getIssue(1).getId());
}

TEST(TestIssueSystem, getUsers) {
    IssueSystem iss;
    vector<User> tempUsers;
    iss.createUser();
    tempUsers = iss.getUsers();
    EXPECT_EQ(tempUsers[0].getId(), iss.getUser(1).getId());
}

TEST(TestIssueSystem, getComments) {
    IssueSystem iss;
    vector<Comment> tempComments;
    iss.createComment();
    tempComments = iss.getComments();
    //don't compare issue directly, compare ID??
    EXPECT_EQ(tempComments[0].getId(), iss.getComment(1).getId());
}

TEST(TestIssueSystem, getIssue_throw) {
    IssueSystem iss;
    EXPECT_THROW(iss.getIssue(-10), std::invalid_argument);
}

TEST(TestIssueSystem, getUser_throw) {
    IssueSystem iss;
    EXPECT_THROW(iss.getUser(-10), std::invalid_argument);
}

TEST(TestIssueSystem, getComment_throw) {
    IssueSystem iss;
    EXPECT_THROW(iss.getComment(-10), std::invalid_argument);
}
