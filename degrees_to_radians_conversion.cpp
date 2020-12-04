#include "gtest/gtest.h"
#include "GameFunctions.h"

TEST(convertDegreesToRadians,whenDegreesAreZero_ExpectCorrectValue)
{
    double compare{1.5708};
    int input{0};
    EXPECT_NEAR(compare, GameFunctions::convert_degrees_to_radians(input),.001);
}

TEST(convertDegreesToRadians,whenDegreesArePositive_ExpectCorrectValue)
{
    double compare{1.09956};
    int input{27};
    EXPECT_NEAR(compare, GameFunctions::convert_degrees_to_radians(input),.001);
}

TEST(convertDegreesToRadians,whenDegreesAreNegative_ExpectCorrectValue)
{
    double compare{1.09956};
    int input{-27};
    EXPECT_NEAR(compare, GameFunctions::convert_degrees_to_radians(input),.001);
}
