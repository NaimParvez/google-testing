#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

class LeapYearTest : public ::testing::Test {
};

TEST_F(LeapYearTest, DivisibleBy4Not100) {
    EXPECT_TRUE(isLeapYear(2024));
    EXPECT_TRUE(isLeapYear(2008));
}

TEST_F(LeapYearTest, DivisibleBy100Not400) {
    EXPECT_FALSE(isLeapYear(1900));
    EXPECT_FALSE(isLeapYear(2100));
}

TEST_F(LeapYearTest, DivisibleBy400) {
    EXPECT_TRUE(isLeapYear(1600));
    EXPECT_TRUE(isLeapYear(2000));
}

TEST_F(LeapYearTest, NotDivisibleBy4) {
    EXPECT_FALSE(isLeapYear(2019));
    EXPECT_FALSE(isLeapYear(2023));
}

TEST_F(LeapYearTest, EdgeCases) {
    EXPECT_FALSE(isLeapYear(0));       // Technically leap, but often disallowed in real calendars
    EXPECT_FALSE(isLeapYear(-400));    // Negative year, invalid in most calendars
    EXPECT_TRUE(isLeapYear(2400));     // Far future, still valid
}

class TestEventListener : public ::testing::EmptyTestEventListener {
public:
    void OnTestEnd(const ::testing::TestInfo& test_info) override {
        if (test_info.result()->Passed()) {
            std::cout << "Test " << test_info.name() << " succeeded." << std::endl;
        }
    }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    listeners.Append(new TestEventListener);
    return RUN_ALL_TESTS();
}
