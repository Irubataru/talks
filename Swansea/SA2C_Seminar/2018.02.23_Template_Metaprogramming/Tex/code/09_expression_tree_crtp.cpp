
/*
 * Created: 21-02-2018
 * Modified: Fri 23 Feb 2018 12:49:16 GMT
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

template <typename T>
struct base_expr
{
  constexpr auto value() const
  {
    return static_cast<T const&>(*this).value();
  }
};

template <long N>
struct integer : base_expr<integer<N>>
{
  using type = integer<N>;

  static constexpr long value()
  {
    return N;
  }
};

template <typename Arg1, typename Arg2>
struct plus_expr : base_expr<plus_expr<Arg1, Arg2>>
{
  constexpr plus_expr(base_expr<Arg1> const& le, base_expr<Arg2> const& re)
    : le_{le}, re_{re} {}

  constexpr auto value() const
  {
    return le_.value() + re_.value();
  }

private:
  base_expr<Arg1> const& le_;
  base_expr<Arg2> const& re_;
};

template <typename Arg1, typename Arg2>
constexpr auto operator+(base_expr<Arg1> const& le, base_expr<Arg2> const& re)
{
  return plus_expr<Arg1, Arg2>(le, re);
}

using five = integer<5>;
using eight = integer<8>;

static_assert((five{} + eight{} + five{}).value() == 18);

int main(int, char **)
{
}
