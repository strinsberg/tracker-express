#include <gtest/gtest.h>
#include "Comment.h"
#include <string>

TEST(TestComment, testConstructor) {
    Comment c(1);
    EXPECT_EQ(1, c.getId());
}

TEST(TestComment, testIssueId) {
    Comment c(1);
    c.setIssueId(2);
    EXPECT_EQ(2, c.getIssueId());
}

TEST(TestComment, testUserId) {
    Comment c(1);
    c.setUserId(3);
    EXPECT_EQ(3, c.getUserId());
}

TEST(TestComment, testCommentText) {
    Comment c(3);
    c.setCommentText("Hello");
    EXPECT_EQ("Hello", c.getCommentText());
}

TEST(TestComment, to_json) {
    Comment com(3);

    auto data = com.toJson();

    EXPECT_EQ(3, data["id"]);
    EXPECT_EQ(-1, data["issue_id"]);
    EXPECT_EQ(-1, data["user_id"]);
    EXPECT_EQ("empty text", data["text"]);
}

TEST(TestComment, update_from_str) {
    std::string data = "{\"issue_id\" : 2, \"user_id\" : 1,"
    "\"text\" : \"stuff\"}";

    Comment com(1);
    com.update(data);

    EXPECT_EQ(2, com.getIssueId());
    EXPECT_EQ(1, com.getUserId());
}
