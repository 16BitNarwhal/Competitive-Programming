#include <bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

int n, k;
bool isPrime(int x) {
  for (int i=2;i<x;i++) {
    if (x % i ==0) 
      return false;
  }
  return true;
}
int main() {
  cin >> n >> k;

  auto start = high_resolution_clock::now();

  int res=0;
  for (int i=2;i<=n;i++) { // O(n)
    if (isPrime(i)) { // O(n)
      int nextPrime=-1;
      for (int j=i+1;j+i+1<=n;j++) { // O(sqrt(n)) ??
        if (isPrime(j)) { 
          nextPrime = j;
          break;
        }
      }
      if (nextPrime==-1) break;
      if (isPrime(i + nextPrime + 1) && i + nextPrime + 1 <= n) {
        res++;
      }
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken: " << duration.count() << " microseconds" << endl;

  cout << (res>=k ? "YES\n" : "NO\n"); 
}