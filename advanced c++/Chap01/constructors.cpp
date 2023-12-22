/*

c++ provides implicit methods for 
  copy constructor, destructor, and copy operator
Rule of three:
if you need to define your own method for any 1 of the above 3,
  you must should define methods for all three
  
*/

#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

// -- interface --
class Animal {
  string _type = "";
  string _name = "";
  string _sound = "";
public:
  Animal(); // default constructor
  Animal(const string & type, const string & name, const string & sound);
  Animal(const Animal &); // copy constructor
  Animal & operator=(const Animal &); // copy assignment operator
  ~Animal(); // destructor
  
  void print() const;
  
};

// -- implementation --
Animal::Animal() : _type(unk), _name(unk), _sound(unk) { 
  // : is a special initializer list syntax
  // _type = unk
  // _name = unk
  // _sound = unk
  puts("default constructor");
}

Animal::Animal(const string & type, const string & name, const string & sound)
: _type(type), _name(name), _sound(sound) {
  // uses : again
  // _type = type ...
  puts("constructor with arguments");
}

Animal::Animal(const Animal & rhs) : _name(clone_prefix + rhs._name),
_type(rhs._type), _sound(rhs._sound) {
  puts("copy constructor");
}

Animal::~Animal() {
  printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print () const {
  printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// overloads the assignment operator
Animal & Animal::operator = (const Animal & rhs) {
  puts("copy operator");
  if (this != &rhs) {
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
  }
  return *this;
}

int main() {
  Animal a;
  a.print();

  const Animal b("cat", "fluffy", "meow");
  b.print();

  const Animal c = b; // use copy constructor
  c.print();

  a = c; // use copy assignment operator
  a.print();

  a = a; // doesn't copy because a and a are the same object (same address)
  a.print();

  return 0;
}