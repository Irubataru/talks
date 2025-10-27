/*
 * Created: 31-05-2018
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include "lib/statistics/average_string.hpp"
#include "gmock/gmock.h"

TEST(Average_String, Fixed_String)
{
  std::string test_string = "Alltid litt moro med Norsk";

  double average = 0.0;
  for (auto c : test_string)
    average += static_cast<int>(c);

  EXPECT_EQ(average / test_string.size(),
            irubataru::statistics::average(test_string));
}

TEST(Average_String, Empty_String)
{
  std::string empty_string = "";

  EXPECT_THAT(irubataru::statistics::average(empty_string),
              ::testing::NanSensitiveDoubleEq(nan("")));
}
