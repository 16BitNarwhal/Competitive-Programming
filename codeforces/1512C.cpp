#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b; cin>>a>>b;
    string s;cin>>s;
    int n = s.length();
    if (a+b != n) {
        cout << "-1\n"; return;
    }
    // fill in known ?s
    for (int i=0;i<n/2;i++) {
        if (s[i]=='?' && s[n-i-1]=='?') continue;
        else if (s[i]=='?')
            s[i] = s[n-i-1];
        else if (s[n-i-1]=='?')
            s[n-i-1] = s[i];
        else if (s[i]!=s[n-i-1]) {
            cout << "-1\n"; return;
        }
    }
    // update counts
    for (int i=0;i<n;i++) {
        a -= (s[i]=='0');
        b -= (s[i]=='1');
    }
    // if n is odd, and middle is ?
    if (n&1 && s[n/2]=='?') {
        // if a is odd, then make middle 0
        // else if b is odd, then make middle 1
        // otherwise, wrong
        if (a&1) {
            s[n/2]='0';
            a--;
        } else if (b&1) {
            s[n/2]='1';
            b--;
        } else {
            cout << "-1\n"; return;
        }
    }
    // fill in unknown ?s
    for (int i=0;i<n;i++) {
        // if there is unknown ?
        if (s[i]=='?' && s[n-i-1]=='?') {
            // if theres a, then update to 0
            // else if theres b, then update to 1
            // else wrong (no more 0s or 1s canbe used)
            if (a>0) {
                s[i] = '0'; s[n-i-1] = '0';
                a -= 2;
            } else if (b>0) {
                s[i] = '1'; s[n-i-1] = '1';
                b -= 2;
            } else {
                cout << "-1\n"; return;
            }
        }
    }
    // if we have exactly 0 0s and 0 1s left to use, then yay
    if (a==0 && b==0) cout << s << '\n';
    else cout << "-1\n";
}
int main() {
    // fast input / output
    ios::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--) solve();
}

/*
T: 5
I: 1 1 3 4
O: 43
I: 3 5 3 7
O: 54
I
O
I
O
*/

/*
cin >> x; // iostream (c++)
scanf(x); // stdio (c)
fast I/O 
ios::sync_with_stdio(false); // unlink iostream and stdio
cin.tie(false); // unlink input and output
*/

/*
T: 5
I: 1 1 3 4
I: 3 5 3 7
I
I
I
O: 43
O: 54
O
O
O
*/