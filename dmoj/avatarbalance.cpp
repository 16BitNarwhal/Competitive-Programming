#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int n, ar[11];
int rec(int i, int a, int b) {
    if (i==n) return abs(a-b);
    return min(rec(i+1, a+ar[i], b),
           rec(i+1, a, b+ar[i]));   
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin>>ar[i];
    cout << rec(0, 0, 0) << '\n';
}