#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin>>N;
    while(N--) {
        int n;cin>>n;
        bool flag=0;
        string ans="";
        for (int i=31;i>=0;i-=4) {
            string res="";
            for (int j=i;j>i-4;j--) {
                if ((n>>j)&1) {
                    flag = 1; res += "1";
                } else {
                    res += "0";
                }
            }
            if (flag) ans += res +" ";
        }
        if (ans=="") cout<<"0000\n";
        else cout<<ans<<'\n';
    }
}


