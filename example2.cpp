#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class example
{
	public:
		int foo()
		{
			return 1;
		}
		
};

TEST(TestName, test1)
{
	example ex;
	ASSERT_EQ(1,ex.foo());
}

TEST(TestName, test2)
{
	example ex;
	ASSERT_NE(0,ex.foo());
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

