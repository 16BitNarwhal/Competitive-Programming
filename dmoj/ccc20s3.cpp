#include <bits/stdc++.h>
using namespace std;

string needle, haystack;
int n, m, res=0;
unordered_map<char, int> fn, fh;
unordered_map<size_t, bool> used;

bool check() {
    for (char i='a';i<='z';i++) {
        if(fn[i] != fh[i]) return 0;
    }
    return 1;
}

int main() {
    cin >> needle >> haystack;
    n = needle.length(); m = haystack.length();
    for (int i=0;i<n;i++) 
        fn[needle[i]]++; 
        
    for (int i=0;i<m-n+1;i++) {
        string s = haystack.substr(i, n);
        if(i==0) {
            for(int j=0;j<n;j++) {
                fh[s[j]]++;
            }
        } else {
            fh[haystack[i+n-1]]++;
            fh[haystack[i-1]]--;
        }
        hash<string> hasher;
        size_t hash = hasher(s);
        if (check() && !used[hash]) {
            used[hash] = 1;
            res++;
        }
    }
    cout << res;
}