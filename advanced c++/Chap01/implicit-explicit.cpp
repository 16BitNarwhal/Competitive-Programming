#include <cstdio>
using namespace std;

class cl {
  int _value = 0;
  // default constructor is private ->
  // prevents default constructor from being called
  cl();
public:
  cl ( const int & value ) : _value(value) {}
  cl ( const int & v1, const int & v2) : _value(v1+v2) {}
  void setvalue(const int & value) { _value = value; }
  int getvalue() const { return _value; }
};

// const cl & o -> uses for suitable constructor
void func(const cl & o) {
  printf("value is %d\n", o.getvalue());
}

int main() {
  // cl o2; // error: private constructor
  
  cl o = 'x'; // implicit conversion from char to int
  printf("value is %d\n", o.getvalue());
  func({'x','y'}); // explicit conversion from char to int

  return 0;
}