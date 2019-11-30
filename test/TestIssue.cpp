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

TEST(TestIssue, test_update_title_desc_priority) {
    Issue iss(1);

    nlohmann::json data = {
        {"title", "some new title"},
        {"description", "trying to figure it out"},
        {"priority", 30},
    };

    iss.update(data.dump());

    EXPECT_EQ("some new title", iss.getTitle());
    EXPECT_EQ("trying to figure it out", iss.getDescription());
    EXPECT_EQ(30, iss.getPriority());
}

TEST(TestIssue, test_update_assignee_creator_status) {
    Issue iss(1);

    nlohmann::json data = {
        {"assignee", 3},
        {"creator", 2},
        {"status", 1},
    };

    iss.update(data.dump());

    EXPECT_EQ(3, iss.getAssignee());
    EXPECT_EQ(2, iss.getCreator());
    EXPECT_EQ(Status::ASSIGNED, iss.getStatus());
}

TEST(TestIssue, test_update_assignee_creator_status_minus) {
    Issue iss(1);

    nlohmann::json data = {
        {"assignee", -1},
        {"creator", 2},
        {"status", 1},
    };

    iss.update(data.dump());

    EXPECT_EQ(-1, iss.getAssignee());
    EXPECT_EQ(2, iss.getCreator());
    EXPECT_EQ(0, iss.getStatus());
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
