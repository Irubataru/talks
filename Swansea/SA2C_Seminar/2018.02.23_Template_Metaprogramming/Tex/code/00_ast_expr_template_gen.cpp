
/*
 * Created: 21-02-2018
 * Modified: Thu 22 Feb 2018 17:36:41 GMT
 * Author: Aleksandra R. Glesaaen (aleksandra@glesaaen.com)
 */

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// Simple names for the operators
struct plus
{
  static std::string to_tex()
  {
    return "+";
  }
};

struct minus
{
  static std::string to_tex()
  {
    return "-";
  }
};

struct times
{
  static std::string to_tex()
  {
    return "*";
  }
};

struct divide
{
  static std::string to_tex()
  {
    return "/";
  }
};

// Base expression used to only need a single
// operator overload for every operator
template <typename Expr>
struct base_expr
{
  auto to_tex() const
  {
    return static_cast<Expr const&>(*this).to_tex();
  };

  auto to_str() const
  {
    return static_cast<Expr const&>(*this).to_str();
  };

  auto width() const
  {
    return static_cast<Expr const&>(*this).width();
  };
};

// A binary expression storing an operator and the two expressions on either
// side
template <typename Op, typename Le, typename Re>
struct binary_expr : base_expr<binary_expr<Op, Le, Re>>
{
public:
  binary_expr(Le const& le, Re const& re)
    : le_{le}, re_{re} {}

  auto to_tex() const
  {
    auto child_width = std::max(std::max(le_.width(), re_.width()), 5ul);

    std::ostringstream oss;
    oss << "node[expression] {\\lstinline!" << to_str() << "!}";
    oss << "  [sibling distance=" << 0.29 * (child_width + 1) << "cm]";
    oss << "  child {" << le_.to_tex() << "}"
        << "  child {node[operator] {\\lstinline!" << Op::to_tex() << "!}}"
        << "  child {" << re_.to_tex() << "}";

    return oss.str();
  }

  auto to_str() const
  {
    return "(" + le_.to_str() + Op::to_tex() + re_.to_str() + ")";
  }

  auto width() const
  {
    return le_.width() + re_.width() + 5;
  }

private:
  Le const & le_;
  Re const & re_;
};

// A leaf class
struct variable : base_expr<variable>
{
public:
  variable(std::string name)
    : name_{name} {}

  auto to_tex() const
  {
    return "node[expr-leaf] {\\lstinline!" + name_ + "!}";
  }

  auto to_str() const
  {
    return name_;
  }

  auto width() const
  {
    return name_.size();
  }

private:
  std::string name_;
};

template <typename Le, typename Re>
auto operator+(base_expr<Le> const& le, base_expr<Re> const& re)
{
  return binary_expr<plus, base_expr<Le>, base_expr<Re>>{le, re};
}

template <typename Le, typename Re>
auto operator-(base_expr<Le> const& le, base_expr<Re> const& re)
{
  return binary_expr<minus, base_expr<Le>, base_expr<Re>>{le, re};
}

template <typename Le, typename Re>
auto operator*(base_expr<Le> const& le, base_expr<Re> const& re)
{
  return binary_expr<times, base_expr<Le>, base_expr<Re>>{le, re};
}

template <typename Le, typename Re>
auto operator/(base_expr<Le> const& le, base_expr<Re> const& re)
{
  return binary_expr<divide, base_expr<Le>, base_expr<Re>>{le, re};
}

variable operator "" _v(const char *str,  std::size_t len)
{
  std::string name(str, str + len);
  return variable{name};
}

variable operator "" _v(unsigned long long i)
{
  return variable{std::to_string(i)};
}

int main()
{
  std::string ofilename = "input/expr_tree.tex";
  std::ofstream ofs{ofilename};

  if (!ofs) {
    std::cerr << "Unable to open output file: \"" << ofilename << "\"\n";
    return 1;
  }

  ofs << "\\" << (
      (3_v * "x"_v) - (( "y"_v + "z"_v) + 4_v)
  ).to_tex() << ";" << std::endl;
  ofs.close();

  ofilename = "input/expr_tree_large.tex";
  ofs.open(ofilename);

  if (!ofs) {
    std::cerr << "Unable to open output file: \"" << ofilename << "\"\n";
    return 1;
  }

  ofs << "\\" << (
      3_v + "x"_v / ("y"_v - 8_v) - ( 3_v * (1_v + "z"_v) / "w"_v) / (2_v - 6_v*"x"_v)
  ).to_tex() << ";" << std::endl;
  ofs.close();
}
