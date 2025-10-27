/*
 * Created: 26-01-2016
 * Modified: Wed 27 Jan 2016 17:54:46 CET
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include<iostream>
#include<boost/type_index.hpp>

using boost::typeindex::type_id_with_cvr;

//End of recursion for "print line" function
void println(std::ostream & os)
{
  os << std::endl;
}

//Generic print line function that can take any number of arguments of any type
template <typename Head, typename... Tail>
void println(std::ostream & os, const Head & head, Tail... tail)
{
  //Uncomment to see types
  //std::cout << "T: "
    //<< type_id_with_cvr<Head>().pretty_name() << ",\t"
    //<< "x: "
    //<< type_id_with_cvr<decltype(head)>().pretty_name() << "\n";

  //os << head;
  //if( sizeof...(tail) != 0)
    //os << ", ";

  println(os,tail...);
}

int main(int, char**)
{
  println(std::cout, 7, 8.43, 'c', "Hello");
  
}
