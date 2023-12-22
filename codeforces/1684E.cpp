#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;cin>>t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int,int> freq;
    for (int i=0;i<n;i++) {
      int x;cin>>x;
      freq[x]++;
    }
    int cst = freq.size();
    int mex=n, cnt=0, num=n;
    // find mex
    for (int i=0;i<n;i++) {
      if (freq.count(i) > 0) {
        num -= freq[i];
        continue;
      }
      cnt++;
      if (cnt>k || cnt>num) {
        mex=i; break;
      }
    }
    // pick least frequencies
    vector<int> v;
    for (auto [x,cnt]: freq) { 
      if (x<mex) {
        cst--; continue;
      }
      v.push_back(cnt);
    }
    sort(v.begin(), v.end());
    // find cost
    for (int c : v) {
      k -= c;
      if (k<0) break;
      cst--;
    }
    cout << cst << '\n';
  }
}