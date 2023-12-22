#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hC, dC, hM, dM, k, plusDmg, plusHp;
// true if player can win
bool check(ll coins) {
  ll playerHp = hC + (coins * plusHp);
  ll playerDmg = dC + ((k-coins) * plusDmg);
  ll playerDie = playerHp / dM + (playerHp%dM > 0);
  ll monsterDie = hM / playerDmg + (hM%playerDmg > 0);
  return playerDie >= monsterDie;
}
int main() {
  int t;cin>>t;
  while (t--) {
    cin >> hC >> dC >> hM >> dM;
    cin >> k >> plusDmg >> plusHp;
    bool ans=false;
    for (ll i=0;i<=k;i++) {
      if (check(i)) {
        ans=true;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}