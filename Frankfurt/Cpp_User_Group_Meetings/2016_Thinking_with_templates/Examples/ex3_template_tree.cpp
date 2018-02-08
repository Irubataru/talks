/*
 * Created: 27-01-2016
 * Modified: Wed 27 Jan 2016 17:57:28 CET
 * Author: Jonas R. Glesaaen (jonas@glesaaen.com)
 */

#include<iostream>
#include<utility>
#include<boost/type_index.hpp>

//Simple names for the operators
struct plus {};
struct minus {};
struct times {};
struct divide {};

//Base expression used to only need a single
//operator overload for every operator
template <typename Expr>
struct base_expr {};

//A binary expression storing an operator and the
//two expressions on either side
template <typename Op, typename Le, typename Re>
struct binary_expr : base_expr<binary_expr<Op,Le,Re>> {};

//A leaf class
struct val : base_expr<val> {};

//Operator that does nothing, only builds the expression tree
//Trailing return type not really needed, mostly for a cleaner syntax
template <typename Le, typename Re>
auto operator+(base_expr<Le>, base_expr<Re>)
  -> binary_expr<plus,Le,Re>
{
  return {};
}

template <typename Le, typename Re>
auto operator-(base_expr<Le>, base_expr<Re>)
  -> binary_expr<minus,Le,Re>
{
  return {};
}

template <typename Le, typename Re>
auto operator*(base_expr<Le>, base_expr<Re>)
  -> binary_expr<times,Le,Re>
{
  return {};
}

template <typename Le, typename Re>
auto operator/(base_expr<Le>, base_expr<Re>)
  -> binary_expr<divide,Le,Re>
{
  return {};
}

//Prints out the expression tree of an arbitrary expression
int main(int, char**)
{
  val v;
  std::cout <<  boost::typeindex::type_id<decltype(v + v - v*v/(v+v))>().pretty_name() << std::endl;
}
