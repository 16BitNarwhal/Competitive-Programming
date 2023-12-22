#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  vector<int> v;
  int i=0;
  for (;i<30;i++) {
    if ((1<<i)>=n) break; 
    cout << "$ 1 " << (1<<i) << " 0" << endl;
    int x;cin>>x;
    v.push_back(x);
  }
  cout << "! " << i-1 << ' ';
  for (int i : v) cout << i << ' ';
  cout << endl;
}
