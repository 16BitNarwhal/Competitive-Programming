#include <bits/stdc++.h>
using namespace std;

int main() {
    // idea is to create equivalence class for strings (log n time)
    // to compare strings in log n time instead of linear time
    string s;
    cin >> s; 
    s += "$";
    int n = s.length();
    vector<int> p(n), c(n);
    {
        // k=0 (first case)
        // take first character of each string
        vector<pair<char, int>> a(n);
        for (int i=0;i<n;i++) a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for (int i=0;i<n;i++) p[i] = a[i].second;
        // build equivalence class of strings
        c[p[0]] = 0;
        for (int i=1;i<n;i++) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    int k=0;
    while ((1 << k) < n) {
        // k -> k+1
        // create/sort array based on previous equivalence class
        vector<pair<pair<int,int>, int>> a(n);
        for (int i=0;i<n;i++) {
            a[i] = {{c[i], c[(i+(1<<k)) % n]}, i};
        }
        sort(a.begin(), a.end());
        for (int i=0;i<n;i++) p[i] = a[i].second;
        // create next equivalence class
        c[p[0]] = 0;
        for (int i=1;i<n;i++) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    for (int i=0;i<n;i++) {
        cout << p[i] << ' ';
    }
}