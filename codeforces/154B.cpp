#include <bits/stdc++.h>
using namespace std;
int spf[100001], ar[100001];
bool active[100001];
void sieve() {
  for (int i=2;i<=100000;i++) spf[i]=i;
  spf[0]=spf[1]=0;
  for (int i=2;i<=100000;i++) {
    if (spf[i]==i) {
      for (int j=i*2;j<=100000;j+=i) {
        if (spf[j]==j) spf[j]=i;        
      }
    }
  }
}
int main() {
  memset(ar, -1, sizeof ar);
  sieve();
  int n, m;
  cin>>n>>m;
  for (int i=0;i<m;i++) {
    char op;cin>>op;
    int col;cin>>col;
    if (op=='+' && active[col]) {
      cout << "Already on\n";
      continue;
    } else if (op=='-' && !active[col]) {
      cout << "Already off\n";
      continue;
    }
    vector<int> primes;
    int x = col;
    while (x > 1) {
      int p = spf[x];
      while (x%p==0) 
        x /= p;
      primes.push_back(p); 
    }
    if (x>1) primes.push_back(x);
    int conflict = -1;
    for (int p : primes) {
      if (op=='+') {
        if (ar[p]!=-1) {
          conflict = ar[p];
          break;
        } 
      }
    }
    if (conflict==-1) {
      if (op=='+') active[col]=true;
      else active[col]=false;
      for (int p : primes) {
        if (op=='+') ar[p] = col;
        else ar[p] = -1;
      }
      cout << "Success\n";
    } else {
      cout << "Conflict with " << conflict << '\n';
    }
  }
}