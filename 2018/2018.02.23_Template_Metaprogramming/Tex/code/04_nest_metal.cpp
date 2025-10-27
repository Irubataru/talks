
/*
 * Created: 22-02-2018
 * Modified: Thu 22 Feb 2018 17:23:55 GMT
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include <metal/metal.hpp>
#include <iostream>
using metal::_1;

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
  :  nest<F, typename metal::invoke<F, X>::type, N-1> {};

template <typename F, typename X>
struct nest<F,X,0>
  :  X {};

int main()
{
  using five = integer<5>;
  return nest<metal::bind<metal::lazy<multiply>,_1,_1>, five, 3>::value;
}
