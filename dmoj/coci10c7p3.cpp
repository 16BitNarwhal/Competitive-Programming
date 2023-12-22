#include <bits/stdc++.h>
using namespace std;
priority_queue<int> S[6];
int N, P;
int main() {
  cin >> N >> P; 
  int ans=0;
  while (N--) {
    int s, x;cin>>s>>x; s--;
    while (!S[s].empty() && S[s].top() > x) { 
      S[s].pop();
      ans++;
    }
    if (S[s].empty() || S[s].top() < x) {
      S[s].push(x);
      ans++;
    }
  }
  cout << ans << '\n';
}