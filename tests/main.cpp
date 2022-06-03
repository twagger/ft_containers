#include "gtest/gtest.h"
# ifdef STD
#  define NS std
# else
#  define NS ft
# endif

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}