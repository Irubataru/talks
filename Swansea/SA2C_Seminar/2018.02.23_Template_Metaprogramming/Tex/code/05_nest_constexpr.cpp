
/*
 * Created: 22-02-2018
 * Modified: Thu 22 Feb 2018 22:23:13 GMT
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include <utility>

constexpr long square(long x)
{
  return x*x;
}

template <typename Function>
constexpr auto nest(Function &&f, long val, long N)
{
  if (N == 0)
    return val;
  else
    return nest(std::forward<Function>(f), f(val), N-1);
}

static_assert(nest(square, 5, 3) == 390625, "");

int main()
{ }
