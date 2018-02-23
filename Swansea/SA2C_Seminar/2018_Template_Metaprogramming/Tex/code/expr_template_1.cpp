
/*
 * Created: 21-02-2018
 * Modified: Wed 21 Feb 2018 14:53:29 GMT
 * Author: Jonas R. Glesaaen
 * (jonas@glesaaen.com)
 */

#include <array>
#include <iostream>

template <typename T, std::size_t Len>
struct Array
{
public:
  template <typename U>
  Array(Array<U, Len> const &arr) : _arr(std::begin(arr), std::end(arr)){};

  template <typename U>
  Array(std::initializer_list<U> init_list)
  {
    if (init_list.size() != Len)
      throw std::invalid_argument{
          "Constructor Array: wrong dim initializer_list"};

    std::copy(init_list.begin(), init_list.end(), _arr.begin());
  }

  auto operator[](std::size_t i) const { return _arr[i]; }

  auto begin() const { return _arr.begin(); }

  auto end() const { return _arr.end(); }

private:
  std::array<T, Len> _arr;
};

template <typename Arg1, typename Arg2>
struct plus_op
{


};

int main()
{
  auto x = Array<double, 5>({5., 2., 3., 6., 1.});
  auto y = Array<double, 5>(x);

  for (auto e : x)
    std::cout << e << " ";

  std::cout << std::endl;
}
