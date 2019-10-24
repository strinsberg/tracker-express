#include <gtest/gtest.h>
#include "Comment.h"

TEST(TestComment, testConstructor) {
    Comment c(1);
    EXPECT_EQ(1, c.getCommentID());
}

TEST(TestComment, testIssueID) {
    Comment c(1);
    c.setIssueID(2);
    EXPECT_EQ(2, c.getIssueID());
}

TEST(TestComment, testUserID) {
    Comment c(1);
    c.setUserID(3);
    EXPECT_EQ(3, c.getUserID());
}

TEST(TestComment, testCommentText) {
    Comment c(3);
    c.setCommentText("Hello");
    EXPECT_EQ("Hello", c.getCommentText());
}
