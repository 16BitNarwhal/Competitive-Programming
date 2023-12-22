#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N, psa[MM], M, grp[MM]; ll ans;
int main() {
    cin >> N;
    for (int i=1,x;i<=N;i++) {
        cin >> x;
        psa[x]++;
        M = max(M,x);
    }
    for (int i=1;i<=M;i++)
        psa[i] += psa[i-1];
    // loop # stones that can be taken first round
    for (int i=1;i<=M;i++) {
        int odd=0; // cnt of odd groups
        // loop each "group" formed of size i
        for (int j=i;j<=M;j+=i) {
            grp[j] = psa[min(i+j-1, M)] - psa[j-1];
            odd += (grp[j]&1);
        }

        if (odd==0 || odd>2) continue; // player 1 cannot win if player 2 plays optimally
        if (odd==1 && (grp[i]&1)) ans += grp[i]; // only if 1 odd group and it's the leftmost
        else if (odd==2) { // if 2 odd groups
            for (int j=i;j<=M;j+=i) { 
                if ( (grp[j-i]&1) && (grp[j]&1) )
                    ans+=grp[j]; // only take the 2 odd groups are adjacent
            }
        }
    }
    cout << ans;
}
