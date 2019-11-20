#include <gtest/gtest.h>
#include "Comment.h"

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
    EXPECT_EQ("nothing", data["text"]);
}
