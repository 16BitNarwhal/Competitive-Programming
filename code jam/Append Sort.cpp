#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 101;
int T,N;
string ar[MM];
bool cmpless(string a, string b, bool equal=0) {
    if (a.length() != b.length()) return a.length() < b.length();
    for(int i=0;i<a.length();i++) {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return equal;
}
void solve(int tc) {
    cin >> N;
    for (int i=0;i<N;i++) cin>>ar[i];
    int ans=0;
    for (int i=1;i<N;i++) {
        if (cmpless(ar[i-1], ar[i])) continue; 
        bool flag=1;
        for (int j=0;j<ar[i].length();j++) {
            if (ar[i][j] != ar[i-1][j]) {
                flag = 0; break;
            }
        }
        if (flag) {
            int n = ar[i].length();
            for (int j=n;j<ar[i-1].length();j++) {
                ar[i] += '0';
                ans++;
            }
            int j;
            for (j=ar[i-1].length()-1;j>=n;j--) {
                if (ar[i-1][j]!='9') {
                    ar[i][j] = (ar[i-1][j]+1);
                    break;
                }
            }
            j--;
            for (;j>=n;j--) {
                ar[i][j] = ar[i-1][j];
            }
        }
        while (cmpless(ar[i], ar[i-1], 1)) {
            ar[i] += "0";
            ans++;
        }  
    }  
    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
}
int main() {
    cin >> T; 
    for (int tc=1;tc<=T;tc++) { 
        solve(tc);
    }
}