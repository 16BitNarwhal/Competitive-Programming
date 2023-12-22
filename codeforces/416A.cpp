#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  int l=-2e9, r=2e9;
  while(n--){
    string op;cin>>op;
    int x;cin>>x;
    char c;cin>>c;
    if (c=='N') {
      if (op==">") op="<=";
      else if (op=="<") op=">=";
      else if (op=="<=") op=">";
      else if (op==">=") op="<";
    }
    if (op==">") l=max(l, x+1);
    else if (op=="<") r=min(r, x-1);
    else if (op==">=") l=max(l, x);
    else if (op=="<=") r=min(r, x);
  }
  if (l<=r) cout << l << '\n';
  else cout << "Impossible\n";
}