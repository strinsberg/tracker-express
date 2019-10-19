#include "gtest/gtest.h"
#include "Issue.h"

TEST(TestIssue, testTitle) {
Issue i;
i.setTitle("Test");
EXPECT_EQ("Test", i.getTitle());
}

TEST(TestIssue, testDescription) {
Issue i;
i.setDescription("Test");
EXPECT_EQ("Test", i.getDescription());
}

TEST(TestIssue, testAssignee) {
Issue i;
i.setAssignee(0);
EXPECT_EQ(0, i.getAssignee());
}

TEST(TestIssue, testTag) {
Issue i;
i.addTag("Test");
EXPECT_EQ("Test", i.getTagAtPos(0));
}

TEST(TestIssue, testTag2) {
Issue i;
i.addTag("Test");
EXPECT_EQ("Test", i.getTags().at(0));
}

TEST(TestIssue, testPriority) {
Issue i;
i.setPriority(1);
EXPECT_EQ(1, i.getPriority());
}

/*
TEST(TestIssue, testStatus) {
Issue i;
i.addStatus("Test");
EXPECT_EQ("Test",i.getTagAtPosition(0));
}
*/


