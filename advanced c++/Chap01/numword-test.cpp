#include <cstdio>
#include "numword.h"
using namespace std;

int main() {
  bw::numword nw;
  uint64_t n;
  n = 3; printf("n is %lld, %s\n", n, nw.words(n));
  n = 47; printf("n is %lld, %s\n", n, nw.words(n));
  n = 73; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1492; printf("n is %lld, %s\n", n, nw.words(n));
  n = 10012; printf("n is %lld, %s\n", n, nw.words(n));
  n = 100073; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1000000; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1000000001; printf("n is %lld, %s\n", n, nw.words(n));
  n = 1474142398007; printf("n is %lld, %s\n", n, nw.words(n));
}