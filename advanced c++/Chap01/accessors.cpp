#include <cstdio>
using namespace std;

class A { 
  int ia;
  const char * sb = "";
  int ic;
  public:
    A(int a, const char * b, int c) : ia(a), sb(b), ic(c) {};
    void seta ( const int a ) { ia = a; }
    void setb ( const char * b ) { sb = b; }
    void setc ( const int c ) { ic = c; }
    int geta () const { return ia; }
    const char * getb () const { return sb; }
    int getc () const { return ic; }
};

int main() {
  
  A a(1, "two", 3);
  printf("ia is %d, sb is %s, ic is %d\n", a.geta(), a.getb(), a.getc());

  return 0;
}
