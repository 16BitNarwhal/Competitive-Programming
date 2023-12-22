#include <cstdio>
using namespace std;

class A { 
private: // optional because private by default
  int _value = 0;
public:
  void setv ( const int a ) { _value = a; };
  
  int getv ();
  // const qualifier marks the method as const safe
  int getv () const;
};

// non-const functions can only be called by mutable objects
int A::getv() {
  puts("mutable getv");
  return _value;
}
// const functions can be called by both mutable and const objects
int A::getv() const {
  puts("const getv");
  return _value;
}

int main() {
  A a;
  a.setv(42);
  printf("a is %d\n", a.getv());

  // method must be const safe
  const A b = a;
  printf("b is %d\n", b.getv());

  return 0;
}