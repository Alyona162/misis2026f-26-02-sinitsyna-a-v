#include <complex/complex.hpp>

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

int failed = 0;

void check(bool ok, const char* name) {
  std::cout << (ok ? "OK   " : "FAIL ") << name << '\n';
  if (!ok) {
    ++failed;
  }
}

bool near(const Complex& a, const Complex& b, double eps = 1e-12) {
  return std::abs(a.re - b.re) < eps && std::abs(a.im - b.im) < eps;
}

std::string to_str(const Complex& z) {
  std::ostringstream os;
  os << z;
  return os.str();
}

void check_constructors() {
  Complex z;
  check(z.re == 0.0 && z.im == 0.0, "default ctor -> {0,0}");

  Complex r(2.5);
  check(r.re == 2.5 && r.im == 0.0, "ctor from real -> {re,0}");

  Complex c(1, -2);
  check(c.re == 1.0 && c.im == -2.0, "ctor from re and im");

  Complex copy(c);
  check(copy == c, "copy ctor");
}

void check_comparison() {
  const Complex a(1, 2);
  check(a == Complex(1, 2), "== equal numbers");
  check(!(a == Complex(1, 3)), "== different im");
  check(!(a == Complex(2, 2)), "== different re");
  check(a != Complex(1, 3), "!= different numbers");
  check(!(a != Complex(1, 2)), "!= equal numbers");
}

void check_unary_minus() {
  check(-Complex(1, -2) == Complex(-1, 2), "unary minus");
  check(-Complex() == Complex(), "unary minus of zero");
}

void check_compound_assignment() {
  Complex z(1, 2);
  z += Complex(3, 4);
  check(z == Complex(4, 6), "+= Complex");

  z += 1.0;
  check(z == Complex(5, 6), "+= double");

  z -= Complex(1, 1);
  check(z == Complex(4, 5), "-= Complex");

  z -= 4.0;
  check(z == Complex(0, 5), "-= double");

  Complex m(1, 2);
  m *= Complex(3, 4);
  check(m == Complex(-5, 10), "*= Complex ((1+2i)*(3+4i) = -5+10i)");

  m *= 2.0;
  check(m == Complex(-10, 20), "*= double");

  Complex d(1, 2);
  d /= Complex(3, 4);
  check(near(d, Complex(0.44, 0.08)), "/= Complex ((1+2i)/(3+4i) = 0.44+0.08i)");

  Complex e(4, 6);
  e /= 2.0;
  check(e == Complex(2, 3), "/= double");

  Complex chain(1, 1);
  (chain += 1.0) += 1.0;
  check(chain == Complex(3, 1), "+= returns reference (chaining)");
}

void check_binary_operators() {
  const Complex a(1, 2);
  const Complex b(3, 4);

  check(a + b == Complex(4, 6), "Complex + Complex");
  check(a + 2.0 == Complex(3, 2), "Complex + double");
  check(2.0 + a == Complex(3, 2), "double + Complex");

  check(a - b == Complex(-2, -2), "Complex - Complex");
  check(a - 2.0 == Complex(-1, 2), "Complex - double");
  check(2.0 - a == Complex(1, -2), "double - Complex");

  check(a * b == Complex(-5, 10), "Complex * Complex");
  check(a * 2.0 == Complex(2, 4), "Complex * double");
  check(2.0 * a == Complex(2, 4), "double * Complex");

  check(near(a / b, Complex(0.44, 0.08)), "Complex / Complex");
  check(a / 2.0 == Complex(0.5, 1), "Complex / double");
  check(near(1.0 / Complex(0, 1), Complex(0, -1)), "double / Complex (1/i = -i)");

  check(a + b == b + a, "addition is commutative");
  check(a * b == b * a, "multiplication is commutative");
  check(Complex(0, 1) * Complex(0, 1) == Complex(-1, 0), "i * i = -1");
  check(near((a * b) / b, a), "(a*b)/b = a");
  check(a - a == Complex(), "a - a = 0");
}

void check_operands_unchanged() {
  const Complex a(1, 2);
  const Complex b(3, 4);
  Complex copy_a = a;
  Complex copy_b = b;
  Complex tmp = a + b;
  tmp = a * b;
  tmp = a - b;
  tmp = a / b;
  check(a == copy_a && b == copy_b, "binary operators do not change operands");
}

void check_output() {
  check(to_str(Complex(4, 6)) == "{4,6}", "output {4,6}");
  check(to_str(Complex(-1.5, 0)) == "{-1.5,0}", "output {-1.5,0}");
  check(to_str(Complex()) == "{0,0}", "output of zero");
}

void check_input() {
  {
    std::istringstream in("{5,6}");
    Complex z;
    in >> z;
    check(in.good() || in.eof(), "input {5,6}: stream ok");
    check(z == Complex(5, 6), "input {5,6}: value");
  }
  {
    std::istringstream in("  {-1.5,2.25}");
    Complex z;
    in >> z;
    check(z == Complex(-1.5, 2.25), "input with spaces and fractions");
  }
  {
    std::istringstream in("5,6}");
    Complex z(9, 9);
    in >> z;
    check(in.fail(), "input without left brace -> fail");
    check(z == Complex(9, 9), "failed input does not change the number");
  }
  {
    std::istringstream in("{5;6}");
    Complex z;
    in >> z;
    check(in.fail(), "input with wrong separator -> fail");
  }
  {
    std::istringstream in("{5,6");
    Complex z;
    in >> z;
    check(in.fail(), "input without right brace -> fail");
  }
  {
    Complex src(3.5, -7);
    Complex dst;
    std::istringstream in(to_str(src));
    in >> dst;
    check(dst == src, "write then read gives the same number");
  }
}

void check_contracts() {
  try {
    Complex z(1, 1);
    z /= 0.0;
    check(false, "z /= 0.0 must throw");
  } catch (const std::invalid_argument& ex) {
    std::cout << "     message: " << ex.what() << '\n';
    check(true, "z /= 0.0 throws invalid_argument");
  }

  try {
    Complex z(1, 1);
    z /= Complex();
    check(false, "z /= Complex(0,0) must throw");
  } catch (const std::invalid_argument&) {
    check(true, "z /= Complex(0,0) throws invalid_argument");
  }

  try {
    Complex r = Complex(1, 1) / 0.0;
    (void)r;
    check(false, "Complex / 0.0 must throw");
  } catch (const std::invalid_argument&) {
    check(true, "Complex / 0.0 throws invalid_argument");
  }

  try {
    Complex r = 1.0 / Complex();
    (void)r;
    check(false, "double / Complex(0,0) must throw");
  } catch (const std::invalid_argument&) {
    check(true, "double / Complex(0,0) throws invalid_argument");
  }

  try {
    Complex z(1, 1);
    z /= Complex(1, 1);
    check(z == Complex(1, 0), "division by non-zero does not throw");
  } catch (...) {
    check(false, "division by non-zero does not throw");
  }
}

}

int main() {
  check_constructors();
  check_comparison();
  check_unary_minus();
  check_compound_assignment();
  check_binary_operators();
  check_operands_unchanged();
  check_output();
  check_input();
  check_contracts();

  if (failed == 0) {
    std::cout << "\nAll tests passed\n";
    return 0;
  }
  std::cout << "\nFailed checks: " << failed << '\n';
  return 1;
}
