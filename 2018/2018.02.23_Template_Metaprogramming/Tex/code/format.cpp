template <typename Arg1, typename Arg2>
constexpr auto
operator+(base_expr<Arg1> const &le,
          base_expr<Arg2> const &re)
{
  return plus_expr<Arg1, Arg2>(le, re);
}

static_assert(
    (five{} + eight{} + five{}).value() == 18);
