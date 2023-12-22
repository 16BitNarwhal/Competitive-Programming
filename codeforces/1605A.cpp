#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int s = a + b + c;
    a = s/3;
    b = (s+1)/3;
    c = (s+2)/3;
    cout << abs(a+c-b-b) << '\n';
  }
}