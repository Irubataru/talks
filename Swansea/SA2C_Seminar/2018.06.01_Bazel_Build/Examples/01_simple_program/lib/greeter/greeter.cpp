/*
 * Created: 31-05-2018
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include "greeter.hpp"
#include "lib/statistics/average_string.hpp"
#include <iostream>

namespace irubataru {

std::string ask_for_name()
{
  std::string name;

  std::cout << "Please give me your name :)\n";
  std::cin >> name;

  return name;
}

void greet_name(std::string const &name)
{
  std::cout << "Hello " << name << ", nice to meet you!\n";
}

void greet_average_name(std::string const &name)
{
  greet_name(name);
  std::cout << "The average ASCII value of your name is: "
            << statistics::average(name) << "\n";
}

} // namespace irubataru
