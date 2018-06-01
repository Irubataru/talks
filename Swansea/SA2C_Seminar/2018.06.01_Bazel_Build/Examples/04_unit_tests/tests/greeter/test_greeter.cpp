/*
 * Created: 31-05-2018
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include "lib/cout_gobbler.hpp"
#include "lib/greeter/greeter.hpp"
#include "gtest/gtest.h"

namespace iru = irubataru;

TEST(Greeter, Test_Normal_Greeter)
{
  iru::Cout_Gobbler gobbler;

  std::string test_name = "Gunnar";
  iru::greet_name(test_name);

  EXPECT_EQ("Hello " + test_name + ", nice to meet you!\n", gobbler.str());
}

TEST(Greeter, Test_Average_Greeter)
{
  iru::Cout_Gobbler gobbler;

  std::string test_name = "Thorgrim";
  iru::greet_average_name(test_name);

  std::ostringstream oss;
  oss << "Hello " << test_name << ", nice to meet you!\n"
      << "The average ASCII value of your name is: 105.5\n";

  EXPECT_EQ(oss.str(), gobbler.str());
}
