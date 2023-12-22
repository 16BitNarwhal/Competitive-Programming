#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long l=0, o=0, v=0, e=0;
    for (int i=s.length()-1;i>=0;i--) {
        if (s[i]=='l') l += o;
        else if (s[i]=='o') o += v;
        else if (s[i]=='v') v += e;
        else if (s[i]=='e') e++;
    }
    cout << l << '\n';
}