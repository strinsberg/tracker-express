#include "IssueSystem.h"
#include "Issue.h"
#include "User.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <stdexcept>
#include <string>
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

    // Because the id is lower this does not increment issueCount
    system.createIssue(tempJson);

    // So the next issue id will still be 4 even though there are 5 issues
    // ignoring the fact that we shouldn't allow a duplicate id.
    EXPECT_EQ(4, system.createIssue());
}

TEST(TestIssueSystem, createIssue_json_higherId) {
    IssueSystem system;
    system.createIssue();

    const char* tempJson =
    "{\"id\" : 6, \"title\" : \"meow\", \"description\" : \"description\","
     "\"assignee\" : -1, \"creator\" : 12, \"priority\" : 132 }";

    system.createIssue(tempJson);
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

    system.createUser(tempJson);
    EXPECT_EQ(4, system.createUser());
}

TEST(TestIssueSystem, createUser_json_higherId) {
    IssueSystem system;
    system.createUser();

    const char* tempJson =
    "{\"id\" : 6, \"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }";

    system.createUser(tempJson);
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

    system.createComment(tempJson);
    EXPECT_EQ(4, system.createComment());
}

TEST(TestIssueSystem, createComment_json_higherId) {
    IssueSystem system;

    const char* tempJson =
    "{\"id\" : 6, \"issue_id\": 12, \"user_id\": 45, \"text\": \"a comment\"}";

    system.createComment(tempJson);
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
    "{\"id\" : 6, \"issue_id\": 1, \"user_id\": 45,"
    "\"text\": \"a comment\"}";

    iss.createComment(tempJson);
    EXPECT_EQ(1, iss.getIssues().size());
    EXPECT_EQ(1, iss.getComments().size());
    iss.removeIssue(1);
    EXPECT_EQ(0, iss.getIssues().size());
    EXPECT_EQ(0, iss.getComments().size());
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
    "{\"id\" : 2, \"user_id\" : 1, \"name\" : \"meow\","
     "\"userID\" : 2, \"blurb\" : \"blurb\","
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
    IssueSystem system;

    const char* tempJson =
    "{\"id\" : 1, \"issue_id\": 1, \"user_id\": 45,"
    "\"text\": \"a comment\"}";

    iss.createComment(tempJson);
    EXPECT_EQ(1, iss.getComments().size());
    iss.removeComment(1);
    EXPECT_EQ(0, iss.getComments().size());
}

TEST(TestIssueSystem, remove_comment_throw) {
    IssueSystem iss;
    iss.createComment();
    EXPECT_THROW(iss.removeComment(2), std::invalid_argument);
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
    "\"text\": \"a comment\", \"tags\": [\"tag\"], \"status\": 1,"
    "\"priority\": 100}";


    const char* tempJson1 =
    "{\"id\" : 2, \"issue_id\": 14, \"user_id\": 45,"
    "\"text\": \"a comment\", \"tags\": [\"pop\", \"chips\"], \"status\": 2,"
    "\"priority\": 100}";

    const char* tempJson2 =
    "{\"id\" : 3, \"issue_id\": 14, \"user_id\": 45,"
    "\"text\": \"a comment\", \"tags\": [\"tag\", \"pop\"], \"status\": 2,"
    "\"priority\": 30}";

    iss.createIssue(tempJson);
    iss.createIssue(tempJson1);
    iss.createIssue(tempJson2);

    EXPECT_EQ(2, iss.filterIssues(100).size());
    EXPECT_EQ(2, iss.filterIssues(-1, "pop").size());
    EXPECT_EQ(1, iss.filterIssues(-1, "tag", 2).size());
    EXPECT_EQ(3, iss.filterIssues().size());
}


TEST(TestIssueSystem, serialize) {
    IssueSystem iss;

    iss.createIssue();
    iss.createUser();
    iss.createComment();

    std::string json = iss.serialize();

    auto data = nlohmann::json::parse(json);
    EXPECT_EQ(2, data["issue_count"]);
    EXPECT_EQ(2, data["comment_count"]);
    EXPECT_EQ(2, data["user_count"]);
    EXPECT_EQ("empty", data["issues"][0]["title"]);
    EXPECT_EQ("empty text", data["comments"][0]["text"]);
    EXPECT_EQ("", data["users"][0]["blurb"]);
}


TEST(TestIssueSystem, deserialize) {
  IssueSystem iss;

  const char* saved = R"({
        "comment_count": 2,
        "comments": [
            {"id":2,"issue_id":2,"text":"I have spoken","user_id":-1}
        ],
        "issue_count": 2,
        "issues": [
            {"assignee":-1,"creator":-1,"description":"This is the way.","id":2,"priority":10,"status":0,"tags":["dfdsf"],"title":"fear it"}
        ],
        "user_count": 2,
        "users": [
            {"blurb":"Distinguish yourself.","id":2,"name":"Mandalorian","pic":4}
        ]})";

  iss.deserialize(saved);
  EXPECT_EQ(iss.getComment(2).getIssueId(), 2);
  EXPECT_EQ(iss.getComment(2).getCommentText(), "I have spoken");
  EXPECT_EQ(iss.getIssue(2).getCreator(), -1);
  EXPECT_EQ(iss.getIssue(2).getDescription(), "This is the way.");
  EXPECT_EQ(iss.getUser(2).getPictureNum(), 4);
  EXPECT_EQ(iss.getUser(2).getName(), "Mandalorian");
}

TEST(TestIssueSystem, clean_string) {
    IssueSystem system;

    const char* tempJson =
    "{\"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }some'/ garbage";

    std::string cleanStr =
    "{\"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 }";

    EXPECT_EQ(cleanStr, system.clean(tempJson));
}

TEST(TestIssueSystem, not_clean_string) {
    IssueSystem system;

    std::string tempJson =
    "{\"name\" : \"meow\", \"blurb\" : \"blurb\", \"pic\" : 1 some'/ garbage";

    EXPECT_EQ(tempJson, system.clean(tempJson));
}
