#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <stdexcept>
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
    IssueSystem system, sys1;

    const char* tempJson =
    "{\"title\" : \"meow\", \"description\" : \"description\","
     "\"assignee\" : -1, \"creator\" : 12, \"priority\" : 132 }";

    Issue& iss = system.createIssue(tempJson);

    EXPECT_EQ("meow", iss.getTitle());
    EXPECT_EQ("description", iss.getDescription());
    EXPECT_EQ(-1, iss.getAssignee());
    EXPECT_EQ(12, iss.getCreator());
    EXPECT_EQ(132, iss.getPriority());
}

TEST(TestIssueSystem, createUser_json) {
    IssueSystem system;

    const char* tempJson =
    "{\"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }";

    User& us = system.createUser(tempJson);

    EXPECT_EQ("meow", us.getName());
    EXPECT_EQ("blurb", us.getBlurb());
    EXPECT_EQ(1, us.getPictureNum());
}

TEST(TestIssueSystem, createUser_json_with_clean_string) {
    IssueSystem system;

    const char* tempJson =
    "{\"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }some'/ garbage";

    User& us = system.createUser(tempJson);

    EXPECT_EQ("meow", us.getName());
    EXPECT_EQ("blurb", us.getBlurb());
    EXPECT_EQ(1, us.getPictureNum());
}

TEST(TestIssueSystem, createComment_json) {
    IssueSystem system;

    const char* tempJson =
    "{\"issue_id\": 12, \"user_id\": 45, \"text\": \"a comment\"}";

    Comment& com = system.createComment(tempJson);

    EXPECT_EQ(1, com.getId());
    EXPECT_EQ(12, com.getIssueId());
    EXPECT_EQ(45, com.getUserId());
    EXPECT_EQ("a comment", com.getCommentText());
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

TEST(TestIssueSystem, to_json) {
    IssueSystem system;

    system.createIssue();
    system.createUser();
    system.createComment();

    auto data = system.toJson();

    EXPECT_EQ(1, data["issues"][0]["id"]);
    EXPECT_EQ(1, data["users"][0]["id"]);
    EXPECT_EQ(1, data["comments"][0]["id"]);

    EXPECT_EQ(2, data["issue_count"]);
    EXPECT_EQ(2, data["user_count"]);
    EXPECT_EQ(2, data["comment_count"]);
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

TEST(TestIssueSystem, remove_issue) {
    IssueSystem iss;
    iss.createIssue();
    EXPECT_EQ(1, iss.getIssues().size());
    iss.removeIssue(1);
    EXPECT_EQ(0, iss.getIssues().size());
}

TEST(TestIssueSystem, remove_issue_throw) {
    IssueSystem iss;
    iss.createIssue();
    EXPECT_THROW(iss.getIssue(2), std::invalid_argument);
}
