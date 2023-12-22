#include <bits/stdc++.h>
using namespace std;
int mem[101];

int main() {
  int n, m;
  cin >> n >> m;
  int cur=1;
  while (n--) {
    string op;
    cin >> op;
    if (op=="alloc") {
      int size; cin >> size;
      int pos=0, cnt=0; // find location with enough space
      for (;pos<m;pos++) {
        if (mem[pos]) cnt=0;
        else {
          cnt++;
          if (cnt>=size) break;
        }
      }
      if (cnt>=size) {
        for (int i=pos-size+1;i<=pos;i++) mem[i] = cur;
        cout << cur++ << '\n';
      } else cout << "NULL\n";
    } else if (op=="erase") {
      long long id; cin >> id;
      bool found=false;
      for (int i=0;i<m;i++) {
        if (id>0 && mem[i]==id) {
          found=true;
          mem[i]=0;
        }
      }
      if (!found) {
        cout << "ILLEGAL_ERASE_ARGUMENT\n";
        continue;
      }
    } else {
      int i=0,j=0;
      for (;i<m && j<m;) {
        while (j<m && mem[j]==0) j++;
        mem[i++] = mem[j++];
      }
      for (;i<m;i++) mem[i]=0;
    }
    // for (int i=0;i<m;i++) 
    //   cout << mem[i];
    // cout << '\n';
  }
}