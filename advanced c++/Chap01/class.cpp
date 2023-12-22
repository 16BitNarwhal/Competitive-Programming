#include <cstdio>
using namespace std;

// class initialized with private members (on default) - used for methods
// class usually defined in a .h file
class cl { 
  int i=0;
  public:
    void setvalue( const int & );
    int getvalue() const;
    int getvalue2() const;
};

// methods usually defined in a .cpp file
void cl::setvalue( const int & value) { 
  i = value;
}
int cl::getvalue() const {
  printf("getvalue: this is %p\n", this); // %p pointer to the object
  return i; 
}
int cl::getvalue2() const {
  printf("getvalue2\n");
  return this -> getvalue(); // this references the object
}

// main code using classes in main.cpp
int main() {
  const int i=47;
  cl o1; // uses implicit default constructor
  o1.setvalue(i);
  printf("value is %d\n", o1.getvalue());

  cl o2 = o1; // uses implicit copy constructor
  printf("value is %d\n", o2.getvalue());

  o1.setvalue(72);
  o2 = o1; // implicit copy / assignment operator
  printf("value is %d\n", o1.getvalue());
  printf("value is %d\n", o2.getvalue()); 

  printf("value is %d\n", o1.getvalue2());

  return 0;
  // all memory is released on default
  // implicit destructors ^^^
}