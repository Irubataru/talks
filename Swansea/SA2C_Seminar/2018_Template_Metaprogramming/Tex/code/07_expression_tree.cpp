
/*
 * Created: 21-02-2018
 * Modified: Thu 22 Feb 2018 23:23:53 GMT
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include <iostream>

template <long N>
struct integer
{
  using type = integer<N>;
  static constexpr long value = N;
};

template <typename Arg1, typename Arg2>
struct plus_expr
  : integer<Arg1::value + Arg2::value>
{};

template <long N, long M>
auto operator+(integer<N>, integer<M>)
{
  return plus_expr<integer<N>, integer<M>>{};
}

int main()
{
  using five = integer<5>;
  using eight = integer<8>;

  auto expr = five{}+eight{};

  std::cout << expr.value << std::endl;
}
