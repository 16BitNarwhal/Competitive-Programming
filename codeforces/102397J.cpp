#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, a;
  cin>>n>>x>>a; 
  int ans = (n+(a/x-1))/(a/x); 
  cout << ans << '\n';
}