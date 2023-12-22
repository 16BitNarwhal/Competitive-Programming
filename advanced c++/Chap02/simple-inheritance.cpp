#include <iostream>
#include <string>
using namespace std;

class Fur {
  string _quality;
  Fur() {}
protected:
  Fur(const string & f) : _quality(f) {}
public:
  const string & quality() const { return _quality; }
};

// animal class (base)
class Animal {
  string _name;
  string _type;
  string _sound;
  // private constructor prevents construction of bas eclass
  Animal() {}
protected:
  // protected constructor for use by dervied class
  Animal ( const string &n , const string & t, const string & s) 
    : _name(n), _type(t), _sound(s) {}
public:
  virtual void speak() const; // go look for speak() in derived class if exists
  const string & name() const { return _name; }
  const string & type() const { return _type; }
  const string & sound() const { return _sound; }
  virtual ~Animal(){} // virtual destructor, required with virtual functions
};

void Animal::speak() const {
  printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - dervied from Animal
class Dog : public Animal {
  int _walked;
public:
  Dog( string n ) : Animal(n, "dog", "woof"), _walked(0) {}
  int walk() { return ++_walked; }
};

// Cat calss - dervied from Animal
class Cat : public Animal, public Fur {
  int _petted;
public:
  Cat( string n ) : Animal(n, "cat", "meow"), Fur("silky"), _petted(0) {}
  int pet() { return ++_petted; }
  void speak() const { Animal::speak(); puts("puurrrrr"); }
};

// Pig class - dervied from Animal
class Pig : public Animal {
  int _fed;
public:
  Pig( string n ) : Animal(n, "pig", "oink"), _fed(0) {}
  string latin() const { return name() + "-ay"; }
  int feed() { return ++_fed; }
};

const string & get_animal_name(const Animal & a) {
  return a.name();
}

int main() {
  Dog d("Rover");
  Cat c("Fluffy");
  Pig p("Arnold");

  d.speak();
  c.speak();
  p.speak();

  cout << "the " << d.type() << " has been walked " << d.walk() << " times" << endl;
  cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;
  cout << "the " << p.type() << " has been fed " << p.feed() << " times" << endl;
  
  Animal *ap[] = { &d, &c, &p };
  for (auto p : ap) {
    // if not virtual, calls Animal::speak(), not Cat::speak()
    // if virtual, calls Cat::speak() or other derived class
    p->speak();
  }
}