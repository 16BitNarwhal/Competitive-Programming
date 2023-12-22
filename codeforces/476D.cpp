#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin>>n>>k;
  cout << (6*(n-1) + 5) * k << '\n';
  vector<int> a = {1,2,3,5};
  for (int i=0;i<n;i++) {
    for (int j : a) 
      cout << (6*i + j) * k << ' ';
    cout << '\n';
  }
} 