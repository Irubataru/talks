/*
 * Created: 31-05-2018
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include "average_string.hpp"
#include <numeric>

namespace irubataru {
namespace statistics {

double average(std::string const &str)
{
  return std::accumulate(
             str.begin(), str.end(), 0.0,
             [](double d, char c) { return d + static_cast<int>(c); }) /
         str.size();
}

} // namespace statistics
} // namespace irubataru
