#include "gtest/gtest.h"
#include "Map.hpp"

/* ************************************************************************** */
/*  MAP CONSTRUCTOR TESTS                                                     */
/* ************************************************************************** */

TEST(MapTest_Constructor, defaultConstructor) {
	ft::map<int> MyMap;
	EXPECT_EQ(MyMap.size(), 0)
		<< "Default map should have a 0 size";
}

