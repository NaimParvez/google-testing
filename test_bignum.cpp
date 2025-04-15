#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Function that mimics the behavior of the main program
int findBiggestNumber(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    } 
}

// Test case for when the first number is the biggest
TEST(BiggestNumberTest, FirstNumberBiggest) {
    EXPECT_EQ(findBiggestNumber(5, 3, 1), 5);
    EXPECT_EQ(findBiggestNumber(10, 10, 5), 10); // First number when tied with second
    EXPECT_EQ(findBiggestNumber(10, 5, 10), 10); // First number when tied with third
}

// Test case for when the second number is the biggest
TEST(BiggestNumberTest, SecondNumberBiggest) {
    EXPECT_EQ(findBiggestNumber(3, 7, 2), 7);
    EXPECT_EQ(findBiggestNumber(5, 10, 10), 10); // Second number when tied with third
}

// Test case for when the third number is the biggest
TEST(BiggestNumberTest, ThirdNumberBiggest) {
    EXPECT_EQ(findBiggestNumber(1, 2, 6), 6);
}

// Test with negative numbers
TEST(BiggestNumberTest, NegativeNumbers) {
    EXPECT_EQ(findBiggestNumber(-5, -3, -10), -3);
    EXPECT_EQ(findBiggestNumber(-1, -2, 0), 0);
}

// Test with all equal numbers
TEST(BiggestNumberTest, AllEqual) {
    EXPECT_EQ(findBiggestNumber(7, 7, 7), 7);
    EXPECT_EQ(findBiggestNumber(-8, -8, -8), -8);
    EXPECT_EQ(findBiggestNumber(0, 0, 0), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}