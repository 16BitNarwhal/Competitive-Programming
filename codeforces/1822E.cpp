#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    string s;cin>>s;
    bool impossible = false;
    if (n&1) {
      impossible = true;
    }
    int freq[26] = {0};
    for (int i=0;i<n;i++) {
      freq[s[i]-'a']++;
    }
    for (int i=0;i<26;i++) {
      if (freq[i] > n/2) {
        impossible = true;
        break;
      }
    }
    // if impossible = false, then we can always make anti-palindrome
    int dfreq[26] = {0}, tot = 0, mx = 0;
    for (int i=0;i<n/2;i++) {
      if (s[i] == s[n-i-1]) {
        dfreq[s[i]-'a']++;
        mx = max(mx, dfreq[s[i]-'a']);
        tot++;
      }
    }
    
    if (impossible) {
      cout << "-1\n";
      continue;
    }

    // pairs = two identical chars, lones = two non-identical chars

    if (mx > tot-mx) { // if a dominant char exists, the # of "dominant" pairs must be swapped (with other pairs/lones)
      cout << mx << '\n';
    } else { // if dominant doesn't exist, then we can swap around all the pairs and leave the lones alone
      cout << (tot+1)/2 << '\n';
    }
  }

}

/*
most popular char m
if dfreq[m] > dfreq[!m]:
  ans = dfreq[m]
else:
  ans = (dfreq[tot]+1)/2

*/