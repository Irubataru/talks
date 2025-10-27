
/*
 * Created: 22-02-2018
 * Modified: Thu 22 Feb 2018 22:58:58 GMT
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include <string>
#include <type_traits>

void only_int(int) {}

template <typename T>
void wont_fail(T x)
{
  if constexpr(std::is_same_v<T, int>)
    only_int(x);
}

int main()
{
  wont_fail(std::string{});
}
