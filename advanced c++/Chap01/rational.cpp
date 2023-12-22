#include <cstdio>
#include <iostream>
using namespace std;

class Rational {
  int _n = 0;
  int _d = 1;
private:
  void reduce() {
    int g = gcd(_n, _d);
    _n /= g;
    _d /= g;
  }
  int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
  }
public:
  Rational ( int numerator = 0, int denominator = 1 ) 
    : _n(numerator), _d(denominator) { reduce(); };
  Rational ( const Rational & rhs ) 
    : _n(rhs._n), _d(rhs._d) { reduce(); }; // copy constructor
  ~Rational ();
  int numerator() const { return _n; };
  int denominator() const { return _d; }; 

  // overload operators
  // name    keyword operator (lhs: object, rhs: argument in method)
  Rational & operator = ( const Rational & );
  // Rational operator + ( const Rational & ) const;
  // Rational operator - ( const Rational & ) const;
  // Rational operator * ( const Rational & ) const;
  // Rational operator / ( const Rational & ) const;

  operator std::string() const;
};

Rational & Rational::operator = ( const Rational & rhs ) {
  if (this != &rhs) { // check for self-assignment
    _n = rhs.numerator();
    _d = rhs.denominator();
    reduce();
  }
  return *this;
}

Rational::operator std::string() const {
  if (_d == 1) return std::to_string(_n);
  else return std::to_string(_n) + "/" + std::to_string(_d);
}

Rational operator + ( const Rational & lhs, const Rational & rhs ) {
  int n = lhs.numerator() * rhs.denominator() + lhs.denominator() * rhs.numerator();
  int d = lhs.denominator() * rhs.denominator();
  return Rational(n, d);
}

Rational operator - ( const Rational & lhs, const Rational & rhs ) {
  int n = lhs.numerator() * rhs.denominator() - lhs.denominator() * rhs.numerator();
  int d = lhs.denominator() * rhs.denominator();
  return Rational(n, d);
}

Rational operator * ( const Rational & lhs, const Rational & rhs) {
  int n = lhs.numerator() * rhs.numerator();
  int d = lhs.denominator() * rhs.denominator();
  return Rational(n, d);
}

Rational operator / ( const Rational & lhs, const Rational & rhs ) {
  int n = lhs.numerator() * rhs.denominator();
  int d = lhs.denominator() * rhs.numerator();
  return Rational(n, d);
}

Rational::~Rational() {
  _n = 0; _d = 1;
}

// overload std::cout with Rational objects
std::ostream & operator << (std::ostream & o, const Rational & r) {
  return o << std::string(r);
}

int main() {

  Rational a = 7;
  cout << "a is: " << a << endl;
  
  Rational b(6, 4);
  cout << "b is: " << b << endl;
  
  Rational c = b; // copy operator
  cout << "c is: " << c << endl;
   
  Rational d; // default constructor
  cout << "d is: " << d << endl;
  d = c; // assignment operator
  cout << "d is: " << d << endl;
  
  Rational & e = d; // reference
  d = e; // assignment to self
  cout << "e is: " << e << endl;

  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;

  std::string s = "Rational value is: ";
  s += b;
  cout << s << endl;

  return 0;

}