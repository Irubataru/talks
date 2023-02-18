/*
 * Created: 04-02-2016
 * Modified: Fri 05 Feb 2016 10:52:38 CET
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>

template <typename T>
class Base
{
public:
  virtual double foo()
  {
    std::cout << "Casting" << std::endl;
    return static_cast<T*>(this)->foo();
  }
};

class Cl1 : public Base<Cl1>
{
public:
  double foo()
  {
    return 4;
  }
};

class Cl2 : public Base<Cl2>
{
public:
  double foo()
  {
    return 5;
  }
};

template <typename Type>
double call(Base<Type> x)
{
  return x.foo();
}

int main(int, char**)
{
  auto x = Cl1 {};
  auto y = Cl2 {};

  std::cout << call(x) << "\n";
  std::cout << call(y) << "\n";
}
