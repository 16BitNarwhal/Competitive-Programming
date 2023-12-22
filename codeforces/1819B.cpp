#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
ll A[MM], B[MM];
int main() {
  int t; cin>>t;
  while (t--) {
    int n; cin>>n;
    ll area=0;
    map<ll,vector<ll>> W, H;
    for (int i=0;i<n;i++) {
      cin >> A[i] >> B[i];
      area += A[i] * B[i];
      H[A[i]].push_back(A[i]);
      W[B[i]].push_back(B[i]);
    }
    // if cut horizontally first
    bool flag=true;
    ll w = (*W.rbegin()).first;
    if (area%w != 0) flag=false;
    ll h = area / w;

  }
}

/*

- use max width block (first cut is horizontal)
- use all blocks w/ same width
- use max height block
- use all blocks w/ same height
- repeat until impossible/no more blocks

*/