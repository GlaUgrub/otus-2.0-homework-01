#include "lib.h"
#include "gtest/gtest.h"

TEST(HelloWorldTests, VersionTest) {
    const unsigned int version = get_version();
    EXPECT_TRUE(version < 0xff);
}




