#include "Issue.h"
#include "gtest/gtest.h"

TEST(TestIssue, testTitle) {
Issue i(1);
i.setTitle("Test");
EXPECT_EQ("Test", i.getTitle());
}

TEST(TestIssue, testDescription) {
Issue i(1);
i.setDescription("Test");
EXPECT_EQ("Test", i.getDescription());
}

TEST(TestIssue, testAssignee) {
Issue i(1);
i.setAssignee(0);
EXPECT_EQ(0, i.getAssignee());
}

TEST(TestIssue, testTag) {
Issue i(1);
i.addTag("Test");
EXPECT_EQ("Test", i.getTagAtPos(0));
}

TEST(TestIssue, testTag2) {
Issue i(1);
i.addTag("Test");
EXPECT_EQ("Test", i.getTags().at(0));
}

TEST(TestIssue, testPriority) {
Issue i(1);
i.setPriority(1);
EXPECT_EQ(1, i.getPriority());
}

TEST(TestIssue, testIdGetter) {
Issue i(1);
EXPECT_EQ(1, i.getIssueId());
}

/*
TEST(TestIssue, testStatus) {
Issue i;
i.addStatus("Test");
EXPECT_EQ("Test",i.getTagAtPosition(0));
}
*/


