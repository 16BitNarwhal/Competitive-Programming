#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,k;
  cin>>n>>m>>k;
  string dir, moves;
  cin >> dir >> dir;
  cin >> moves;
  dir = (dir=="head") ? "L" : "R";
  
  bool flag=0;
  int cnt=0;
  for (char move : moves) {
    cnt++;

    if (move == '0') {
      // move away
      if (k > m) {
        m = max(1, m-1);
      } else {
        m = min(n, m+1);
      } 
    }
 
    // move controller and swap dir if needed
    if (dir=="L") {
      k--;
      if (k==1) dir="R";
    } else if (dir=="R") {
      k++;
      if (k==n) dir="L";
    }
     
    // move to opposite end of train (if can)
    if (move=='1') {
      if (dir=="L") {
        if (k==n) m = 1;
        else m = n;
      } else {
        if (k==1) m = n;
        else m = 1;
      }
    }

    if (m==k) { flag=1; break; }
  }
  if (flag) cout << "Controller " << cnt << '\n';
  else cout << "Stowaway\n";

}

/*
let C be controller
let S be stowaway

wagons:
.SC...

train move:
0001001

*/