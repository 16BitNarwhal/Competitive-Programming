#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b){
  return a + rand() % (b - a + 1);
} 
int main(int argc, char* argv[]){
  // int seed = atoi(argv[1]);
  int seed = 9;
  srand(seed); 
  cout << "1\n";
  string A="abcdefg";
  // abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
  string B = A;
  // shuffle A
  for (int i=0;i<A.size();i++) {
    int j = rnd(i,A.size()-1);
    swap(A[i],A[j]);
  }
  // shuffle B
  for (int i=0;i<B.size();i++) {
    int j = rnd(i,B.size()-1);
    swap(B[i],B[j]);
  }
  cout << A << endl << B << endl;
}
