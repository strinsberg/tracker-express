#include "gtest/gtest.h"
#include "Issue.h"
#include "Status.h"

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
    EXPECT_EQ(1, i.getId());
}

TEST(TestIssue, testCreator) {
    Issue i(1);
    i.setCreator(42);
    EXPECT_EQ(42, i.getCreator());
}


TEST(TestIssue, testStatus) {
    Issue i(1);
    i.setStatus(Status::NEW);
    EXPECT_EQ(Status::NEW, i.getStatus());
}

TEST(TestIssue, test_to_json_string) {
    Issue iss(1);

    auto data = iss.toJson();

    EXPECT_EQ(1, data["id"]);
    EXPECT_EQ("empty", data["title"]);
    EXPECT_EQ("empty", data["description"]);
    EXPECT_EQ(-1, data["assignee"]);
    EXPECT_EQ(-1, data["creator"]);
    EXPECT_EQ(-1, data["priority"]);
    // add tags when they are ready
}
