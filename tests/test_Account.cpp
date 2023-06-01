#include <Account.h>
#include <gtest/gtest.h>

TEST(Account, Banking){
	Account test(0,0);
	ASSERT_EQ(test.GetBalance(), 0);
	ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);
	test.Lock();
	ASSERT_NO_THROW(test.ChangeBalance(100));
	ASSERT_EQ(test.GetBalance(), 100);
	ASSERT_THROW(test.Lock(), std::runtime_error);
	test.Unlock();
	ASSERT_THROW(test.ChangeBalance(100), std::runtime_error);
}
