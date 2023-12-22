#include <bits/stdc++.h>
using namespace std;

// log(a) + log(b) = log(a*b)
// len(inp) can substitute for log(inp) when using numbers > 10!
int fact[11];
double a[(int)1e6+1];
int main() {
    string s;cin>>s;
    int l = s.length();
    fact[0]=1;
    for(int i=1;i<=10;i++)
        fact[i] = i * fact[i-1];

    a[0] = 0;
    for(int i=1;i<=(int)1e6;i++) 
        a[i] = a[i-1] + log10(i);
    
    if(l<=7) { // num <= 10!
        int num = stoi(s);
        for(int i=1;i<=10;i++) {
            if(fact[i]==num) {
                cout<<i<<'\n';
                return 0;
            }
        }
    } else {
        double mn = 1e9;
        int res = -1;
        for(int i=11;i<=1e6;i++) {
            double d = abs(l-a[i]);
            if(d < mn) {
                mn = d;
                res = i;
            }
        }
        cout<<res<<'\n';
    }
}