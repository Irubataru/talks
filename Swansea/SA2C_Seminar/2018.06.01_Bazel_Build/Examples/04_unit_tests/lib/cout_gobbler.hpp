
/*
 * Created: 31-05-2018
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#ifndef COUT_GOBBLER_HPP
#define COUT_GOBBLER_HPP

#include <string>
#include <iostream>
#include <sstream>

namespace irubataru {

class Cout_Gobbler
{
public:
  Cout_Gobbler()
  {
    original_stream = std::cout.rdbuf();
    std::cout.rdbuf(redirect_stream.rdbuf());
  }

  std::string const str() const
  {
    return redirect_stream.str();
  }

  ~Cout_Gobbler()
  {
    std::cout.rdbuf(original_stream);
  }

private:
  std::ostringstream redirect_stream;
  std::streambuf *original_stream;
};

} // namespace irubataru

#endif /* COUT_GOBBLER_HPP */
