#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "includes/animate.h"
#include "includes/game/display.h"
using namespace std;

bool basic_test(bool debug = true)
{
  cout << endl
       << "hello world!" << endl
       << endl;
  return true;
}

bool test_animate(bool debug = true)
{
  display game;
  game.run();
  return true;
}

TEST(BASIC_TEST, BasicTest)
{
  EXPECT_EQ(1, basic_test(false));
}

TEST(TEST_ANIMATE, TestAnimate)
{
  EXPECT_EQ(1, test_animate(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  cout << "\n\n----------running basic_test.cpp---------\n\n"
       << endl;
  return RUN_ALL_TESTS();
}
