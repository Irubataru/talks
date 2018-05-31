
/*
 * Created: 22-02-2018
 * Modified: Thu 22 Feb 2018 15:47:01 GMT
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include <brigand/brigand.hpp>
#include <type_traits>
using brigand::_1;

template <long N>
struct integer
{
  using type = integer<N>;
  static constexpr long value = N;
};

template <typename Arg1, typename Arg2>
struct multiply
  : integer<Arg1::value * Arg2::value> {};

template <typename F, typename X, unsigned N>
struct nest
  :  nest<F, typename brigand::apply<F, X>::type, N-1> {};

template <typename F, typename X>
struct nest<F,X,0>
  :  X {};

int main()
{
  static_assert(std::is_same<brigand::true_type, brigand::bool_<true>>::value);

  using five = integer<5>;
  return nest<multiply<_1, _1>, five, 3>::value;
}
