#include <bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

int n, k;
bool isPrime[100001];
vector<int> primes;

// Sieve of Eratosthenes : O(n log log n)
void sieve() {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = 0;
  for (int i=2;i<=n;i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j=2*i;j<=n;j+=i)
        isPrime[j]=false;
    }
  }
} 

int main() {
  cin >> n >> k;

  auto start = high_resolution_clock::now();

  sieve(); // O(n log log n)
  int res=0;
  // number primes between 1 and n is roughly n / ln(n)
  for (int p : primes) { // O(n / ln(n))
    for (int i=0;i<primes.size()-1;i++) { // O(n / ln(n))
      if (primes[i]>=p) break;  
      if (p == primes[i] + primes[i+1] + 1) { 
        res++;
        break;
      }
    }
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken: " << duration.count() << " microseconds" << endl;

  cout << (res>=k ? "YES\n" : "NO\n");
  
  // O(n log log n + n^2 / ln(n)^2)
}
