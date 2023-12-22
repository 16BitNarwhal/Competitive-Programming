// KMP (works)
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e6+2; 
int p[MM], n, m, ans=-1;
string s, t;
int main() {
    cin >> s >> t;
    s = t + "#" + s;
    n = s.length(), m = t.length();
    p[0]=0;
    for (int i=1;i<n;i++) {
        int j = p[i-1];
        while (j>0 && s[i]!=s[j]) 
            j=p[j-1];
        j += s[i]==s[j];
        p[i] = j;
        if (p[i]==m) {
            ans = i-m-m; break;
        }
    }
    cout << ans;
}

// // Rabin karp (WA at testcase 7)
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;  
// const int p=53, m=1e9+9, MM = 1e6+2; 
// ll ppow[MM], h[MM];
// string s, t;
// int main() {
//     cin >> s >> t;
//     int n = s.length(), l = t.length(); 
//     ppow[0] = 1;
//     for (int i=1;i<n;i++)
//         ppow[i] = (ppow[i-1]*p)%m; 
//     for (int i=0;i<n;i++)
//         h[i+1] = (h[i] + (s[i]-'a'+1) * ppow[i]) % m;
//     ll hashh=0;
//     for (int i=0;i<l;i++)
//         hashh = (hashh + (t[i]-'a'+1) * ppow[i]) % m;
//     int ans=-1;
//     for (int i=0;i+l<n;i++) {
//         if ((h[i+l]-h[i]+m)%m == (hashh*ppow[i])%m) {
//             ans = i; break;
//         }
//     }
//     cout << ans;
// }