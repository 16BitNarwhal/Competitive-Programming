#include <bits/stdc++.h>
using namespace std;
// pls work?
#define o 0
#define O 1
#define a 2
#define A 3
#define b 4
#define B 5
#define ab 6
#define AB 7
struct blood {
  int amnt, cap, fill=0;
} ar[8]; 
void add(int i, int j) {
  int x = min(ar[i].cap - ar[i].fill, ar[j].amnt); 
  ar[i].fill += x;
  ar[j].amnt -= x;
}
int main() {
  for (int i=0;i<8;i++) cin >> ar[i].amnt;
  for (int i=0;i<8;i++) cin >> ar[i].cap;
  for (int i=0;i<8;i++) add(i, i);
  for (int i=0;i<8;i+=2) add(i+1, i);

  add(AB, A); add(ab, a);
  add(AB, B); add(ab, b);
  add(AB, a);
  add(AB, b);

  add(A, O); add(a, o);
  add(B, O); add(b, o);
  add(A, o); 
  add(B, o);

  add(AB, O); 
  add(ab, o);
  add(AB, o);
  
  int ans=0;
  for (int i=0;i<8;i++) ans += ar[i].fill;
  cout << ans << '\n';
}