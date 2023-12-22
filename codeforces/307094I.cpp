#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, s, ar[MM];
struct stack {
  vector<int> v;
  vector<bitset<1001>> val;
  void init() {
    bitset<1001> temp;
    temp[0] = 1;
    val.push_back(temp);
  }
  void push(int x) {
    v.push_back(x);
    val.push_back(val.back() | (val.back() << x));
  }
  bitset<1001> get() {
    return val.back();
  }
  int pop() {
    int x = v.back();
    v.pop_back();
    val.pop_back();
    return x;
  }
  bool empty() {
    return v.empty();
  }
} s1, s2;
void add(int x) {
  s2.push(x);
}
void remove() {
  if (s1.empty()) {
    while (!s2.empty()) 
      s1.push(s2.pop());
  }
  s1.pop();
}
bool good() {
  auto a=s1.get(), b=s2.get();
  for (int i=0;i<=s;i++) {
    if (a[i] && b[s-i]) return true;
  }
  return false;
}
int main() {
  cin >> n >> s;
  for (int i=0;i<n;i++) cin >> ar[i];
  s1.init(); s2.init();
  int l=0, ans=1e9; 
  for (int r=0;r<n;r++) {
    add(ar[r]);
    while (good()) {
      ans = min(ans, r-l+1);
      remove();
      l++;
    }
  }
  cout << (ans==1e9?-1:ans) << '\n';
}