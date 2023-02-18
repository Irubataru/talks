
/*
 * Created: 23-02-2018
 * Modified: Fri 23 Feb 2018 12:27:16 GMT
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

template <typename T>
struct base_expr
{ };

template <long N>
struct integer : base_expr<integer<N>>
{
  using type = integer<N>;
  static constexpr long value = N;
};

template <typename Arg1, typename Arg2>
struct plus_expr : base_expr<plus_expr<Arg1, Arg2>>
{
  using type = integer<Arg1::value + Arg2::value>;
  static constexpr long value = type::value;
};

template <typename Arg1, typename Arg2>
constexpr auto operator+(base_expr<Arg1>, base_expr<Arg2>)
  -> plus_expr<Arg1, Arg2>
{ return {}; }

using five = integer<5>;
using eight = integer<8>;

static_assert(decltype(five{} + eight{} + five{})::value == 18, "");

int main(int, char **)
{
}
