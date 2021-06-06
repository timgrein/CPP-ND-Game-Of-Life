#include <gtest/gtest.h>
#include <utils/Utils.h>

class UtilsTest : public ::testing::Test{};

TEST_F(UtilsTest, TestGetRandomOneOrZero){
    bool at_least_one_zero_appears = false;
    bool at_least_one_one_appears = false;

    // 0,5 ^ 400, that every number is a 0 or every number is a 1
    for(int i = 0; i < 400; i++){
        if(Utils::GetRandomOneOrZero() == 0){
            at_least_one_zero_appears = true;
        } else if(Utils::GetRandomOneOrZero() == 1){
            at_least_one_one_appears = true;
        }
    }

    EXPECT_TRUE(at_least_one_one_appears);
    EXPECT_TRUE(at_least_one_zero_appears);
}