
/*
 * Created: 20-02-2018
 * Modified: Wed 21 Feb 2018 15:15:19 GMT
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

template <long N>
struct integer
{
  using type = integer<N>;
  static constexpr long value = N;
};

template <typename Arg1, typename Arg2>
struct multiply
{
  using type = integer<Arg1::value * Arg2::value>;
};

struct square_f
{
  template <typename Arg>
  struct apply
    :  multiply<Arg, Arg> {};
};

template <typename F, typename X, unsigned N>
struct nest
  :  nest<F, typename F::template apply<X>::type, N-1> {};

template <typename F, typename X>
struct nest<F,X,0>
  :  X {};

int main()
{
  using five = integer<5>;
  using result = nest<square_f, five, 3>::type;
  return result::value;
}
