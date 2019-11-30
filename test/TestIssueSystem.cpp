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

TEST(TestIssueSystem, createIssue_json_lowerId) {
    IssueSystem system;
    system.createIssue();
    system.createIssue();
    system.createIssue();

    const char* tempJson =
    "{\"id\" : 2, \"title\" : \"meow\", \"description\" : \"description\","
     "\"assignee\" : -1, \"creator\" : 12, \"priority\" : 132 }";

    Issue& iss = system.createIssue(tempJson);
    EXPECT_EQ(4, system.createIssue());
}

TEST(TestIssueSystem, createIssue_json_higherId) {
    IssueSystem system;
    system.createIssue();

    const char* tempJson =
    "{\"id\" : 6, \"title\" : \"meow\", \"description\" : \"description\","
     "\"assignee\" : -1, \"creator\" : 12, \"priority\" : 132 }";

    Issue& iss = system.createIssue(tempJson);
    EXPECT_EQ(7, system.createIssue());
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

TEST(TestIssueSystem, createUser_json_lowerId) {
    IssueSystem system;
    system.createUser();
    system.createUser();
    system.createUser();

    const char* tempJson =
    "{\"id\" : 2, \"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }";

    User& us = system.createUser(tempJson);

    EXPECT_EQ(4, system.createUser());
}

TEST(TestIssueSystem, createUser_json_higherId) {
    IssueSystem system;
    system.createUser();

    const char* tempJson =
    "{\"id\" : 6, \"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }";

    User& us = system.createUser(tempJson);

    EXPECT_EQ(7, system.createUser());
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

TEST(TestIssueSystem, createComment_json_lowerId) {
    IssueSystem system;
    system.createComment();
    system.createComment();
    system.createComment();

    const char* tempJson =
    "{\"id\" : 2, \"issue_id\": 12, \"user_id\": 45, \"text\": \"a comment\"}";

    Comment& com = system.createComment(tempJson);

    EXPECT_EQ(4, system.createComment());
}

TEST(TestIssueSystem, createComment_json_higherId) {
    IssueSystem system;

    const char* tempJson =
    "{\"id\" : 6, \"issue_id\": 12, \"user_id\": 45, \"text\": \"a comment\"}";

    Comment& com = system.createComment(tempJson);

    EXPECT_EQ(7, system.createComment());
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

TEST(TestIssueSystem, remove_issue) {
    IssueSystem iss;
    iss.createIssue();

    const char* tempJson =
    "{\"id\" : 6, \"issue_id\": 12, \"user_id\": 45,"
    "\"text\": \"a comment\"}";

    iss.createIssue(tempJson);

    EXPECT_EQ(2, iss.getIssues().size());
    iss.removeIssue(1);
    EXPECT_EQ(1, iss.getIssues().size());
    //EXPECT_EQ()
}

TEST(TestIssueSystem, remove_issue_throw) {
    IssueSystem iss;
    iss.createIssue();
    EXPECT_THROW(iss.removeIssue(2), std::invalid_argument);
}

TEST(TestIssueSystem, remove_user) {
    IssueSystem iss;

    const char* tempJson =
    "{\"id\" : 2, \"name\" : \"meow\", \"blurb\" : \"blurb\","
    " \"assignee\" : 1, \"creator\" : 2, \"pic\" : 1 }";

    iss.createUser();
    iss.createUser(tempJson);

    const char* tempJson1 =
    "{\"id\" : 2, \"name\" : \"meow\", \"blurb\" : \"blurb\","
    " \"assignee\" : 1, \"creator\" : 2, \"pic\" : 1 }";

    iss.createIssue(tempJson1);

    const char* tempJson2 =
    "{\"id\" : 2, \"name\" : \"meow\", \"userID\" : 2, \"blurb\" : \"blurb\","
    " \"assignee\" : 1, \"creator\" : 2, \"pic\" : 1 }";

    iss.createComment(tempJson2);
    EXPECT_EQ(2, iss.getUsers().size());
    iss.removeUser(1);
    EXPECT_EQ(1, iss.getUsers().size());
    iss.removeUser(2);
    EXPECT_EQ(0, iss.getUsers().size());
}

TEST(TestIssueSystem, remove_user_throw) {
    IssueSystem iss;
    iss.createUser();
    EXPECT_THROW(iss.removeUser(2), std::invalid_argument);
}

TEST(TestIssueSystem, remove_comment) {
    IssueSystem iss;
    iss.createComment();
    EXPECT_THROW(iss.removeComment(2), std::invalid_argument);

    const char* tempJson =
    "{\"id\" : 1, \"issue_id\": 1, \"user_id\": 45,"
    "\"text\": \"a comment\"}";

    iss.createComment(tempJson);
    iss.removeComment(1);
    //what to expect here
}

TEST(TestIssueSystem, filter_comments) {
    IssueSystem iss;
    iss.createComment();
    iss.createComment();
    iss.createComment();

    const char* tempJson =
    "{\"id\" : 1, \"issue_id\": 14, \"user_id\": 45,"
    "\"text\": \"a comment\"}";
    iss.createComment(tempJson);

    EXPECT_EQ(1, iss.filterComments(14).size());
    EXPECT_EQ(3, iss.filterComments(-1).size());
}

TEST(TestIssueSystem, filter_issues) {
    IssueSystem iss;

    const char* tempJson =
    "{\"id\" : 1, \"issue_id\": 14, \"user_id\": 45,"
    "\"text\": \"a comment\", \"tag\": \"tag\", \"status\": 10,"
    "\"priority\": 100}";

    iss.createIssue(tempJson);

    EXPECT_EQ(1, iss.filterIssues(100, "tag", 10).size());
    const char* tempJson1 =
    "{\"id\" : 1, \"issue_id\": 14, \"user_id\": 45,"
    "\"text\": \"a comment\", \"tag\": \"\", \"status\": -1,"
    "\"priority\": -1}";

    iss.createIssue(tempJson1);
    EXPECT_EQ(2, iss.filterIssues(100, "tag", 10).size());
}


TEST(TestIssueSystem, serialize) {
  IssueSystem iss;

  iss.createIssue();
  iss.createUser();
  iss.createComment();

  std::string json = iss.serialize();
}


TEST(TestIssueSystem, deserialize) {
  IssueSystem iss;

  const char* saved = R"({
        "comment_count": 2,
        "comments": [ 
            {"id":2,"issue_id":2,"text":"hello","user_id":-1}
        ],
        "issue_count": 2,
        "issues": [
            {"assignee":-1,"creator":-1,"description":"Type your description here.","id":2,"priority":10,"status":0,"tags":["dfdsf"],"title":"fear it"}
        ],
        "user_count": 2,
        "users": [
            {"blurb":"Distinguish yourself.","id":2,"name":"sfsdfsdfs","pic":2}
        ]})";

  iss.deserialize(saved);
}
