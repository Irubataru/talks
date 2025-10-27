/*
 * Created: 05-02-2016
 * Modified: Fri 05 Feb 2016 11:26:13 CET
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>

template <typename Type>
class Counter
{
public:
  Counter()
  {
    ++instances;
  }

  ~Counter()
  {
    --instances;
  }

  static unsigned instances;
};

class A : public Counter<A> {};
class B : public Counter<B> {};

template <typename Type>
unsigned Counter<Type>::instances = 0;

int main(int, char**)
{
  A a1, a2, a3, a4;
  B b1, b2;
  std::cout << Counter<B>::instances << std::endl;
}
