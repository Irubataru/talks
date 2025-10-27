
/*
 * Created: 31-05-2018
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include <iostream>
#include "lib/greeter/greeter.hpp"

namespace iru = irubataru;

int main(int, char**)
{
  auto name = iru::ask_for_name();
  iru::greet_average_name(name);
}
