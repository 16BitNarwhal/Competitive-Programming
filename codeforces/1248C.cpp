#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2, mod = 1e9+7;
int n, m, fib[MM];
int main() {
  cin>>n>>m;
  fib[0]=fib[1]=1;
  for (int i=2; i<MM; i++) 
    fib[i] = (fib[i-1]+fib[i-2])%mod;
  cout << 2*((fib[n]+fib[m]-1)%mod)%mod << endl;
}

/*

fib[n] <= # ways to fill with blocks size 1 and 2

except for blocks of ONLY size 1, rows / columns alternate
-1 removes duplicate way for only size 1
fib[n] + fib[m] - 1

2 colors so multiply by 2
2 * (fib[n] + fib[m] - 1) 

*/