/*
 * Created: 27-01-2016
 * Modified: Wed 27 Jan 2016 17:54:20 CET
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>
#include<utility>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

// Template type deducion case 1
// ParamType is a reference or pointer but not universal reference
template <typename T>
void f(T& x)
{
  std::cout << "T: "
    << type_id_with_cvr<T>().pretty_name() << ",\t"
    << "x: "
    << type_id_with_cvr<decltype(x)>().pretty_name() << "\n";
}

// Template type deducion case 2
// ParamType is a not universal reference
template <typename T>
void g(T&& x)
{

  std::cout << "T: "
    << type_id_with_cvr<T>().pretty_name() << ",\t"
    << "x: "
    << type_id_with_cvr<decltype(x)>().pretty_name() << "\n";
}

// Template type deducion case 3
// ParamType is a not a reference nor a pointer
template <typename T>
void h(T x)
{
  std::cout << "T: "
    << type_id_with_cvr<T>().pretty_name() << ",\t"
    << "x: "
    << type_id_with_cvr<decltype(x)>().pretty_name() << "\n";
}

int main(int, char**)
{
  int x;
  int& rx = x;
  const int & crx = x;

  std::cout << "template <typename T>\n"
    << "void f(T& x)" << "\n";

  f(x);
  f(rx);
  f(crx);

  std::cout << "\n" << "template <typename T>\n"
    << "void g(T&& x)" << "\n";

  g(x);
  g(rx);
  g(crx);
  g(27);

  std::cout << "\n" << "template <typename T>\n"
    << "void h(T x)" << "\n";

  h(x);
  h(rx);
  h(crx);
  
}
