
/*
 * Created: 31-05-2018
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#ifndef GREETER_HPP
#define GREETER_HPP

#include <string>

namespace irubataru {

std::string ask_for_name();
void greet_name(std::string const&);
void greet_average_name(std::string const&);

} // namespace irubataru

#endif /* GREETER_HPP */
