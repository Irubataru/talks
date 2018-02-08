/*
 * Created: 26-01-2016
 * Modified: Wed 27 Jan 2016 17:59:23 CET
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

//A function that demonstrates that the array size of a C-array
//is encoded into the type, and that this is accessible information
template <typename T, std::size_t N>
constexpr std::size_t array_size(T (&)[N]) noexcept
{
  return N;
}

//This function demonstrates some caveats when template deducing
//C-arrays. Only array references retain information about array size
//(does not compile for a call-by-value)
template <typename T>
void print_arr(const T& arr)
{
  std::cout << "[" << array_size(arr) << "] ";
  for (auto i : arr)
    std::cout << i << ", ";

  std::cout << "\n";

  //Uncomment to print out the deduced types of T and arr
  //std::cout << "T: "
    //<< type_id_with_cvr<T>().pretty_name() << ",\t"
    //<< "x: "
    //<< type_id_with_cvr<decltype(arr)>().pretty_name() << "\n";
}

int main(int, char**)
{
  int arr[] = {3, 1, 4, 1, 5, 9};
  print_arr(arr);
}
