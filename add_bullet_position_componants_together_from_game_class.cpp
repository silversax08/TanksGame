#include "gtest/gtest.h"
#include "GameFunctions.h"

TEST(addBulletPositionComponantsTogether,whenTankPositionIs0AndAngleIs0_ExpectCorrectValue)
{
    std::array<int,2> compare{60,0};
    int angle{0};
    std::array<int,2> position{0,0};
    std::array<int,2> newPosition{GameFunctions::add_bullet_position_componants_together(angle,position)};
    EXPECT_NEAR(compare[0],newPosition[0],1);
    EXPECT_NEAR(compare[1],newPosition[1],1);
}

TEST(addBulletPositionComponantsTogether,whenTankPositionIs0AndAngleIsPositive_ExpectCorrectValue)
{
    std::array<int,2> compare{120,60};
    int angle{90};
    std::array<int,2> position{0,0};
    std::array<int,2> newPosition{GameFunctions::add_bullet_position_componants_together(angle,position)};
    EXPECT_NEAR(compare[0],newPosition[0],1);
    EXPECT_NEAR(compare[1],newPosition[1],1);
}

TEST(addBulletPositionComponantsTogether,whenTankPositionIs0AndAngleIsNegative_ExpectCorrectValue)
{
    std::array<int,2> compare{0,60};
    int angle{-90};
    std::array<int,2> position{0,0};
    std::array<int,2> newPosition{GameFunctions::add_bullet_position_componants_together(angle,position)};
    EXPECT_NEAR(compare[0],newPosition[0],1);
    EXPECT_NEAR(compare[1],newPosition[1],1);
}

TEST(addBulletPositionComponantsTogether,whenTankPositionIs100AndAngleIs0_ExpectCorrectValue)
{
    std::array<int,2> compare{160,100};
    int angle{0};
    std::array<int,2> position{100,100};
    std::array<int,2> newPosition{GameFunctions::add_bullet_position_componants_together(angle,position)};
    EXPECT_NEAR(compare[0],newPosition[0],1);
    EXPECT_NEAR(compare[1],newPosition[1],1);
}
