#include <bits/stdc++.h>
using namespace std;
const int MM=22;
int n, a[MM], b[MM], cnt;
long long res = 1;

int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    for(int i=0;i<n;i++) { 
        cnt = 0;
        for(int j=0;j<n;j++) {
            if(a[i] <= b[j]) cnt++;
            else break;
        }
        res *= (cnt-i);
    }
    cout<<(res<0?0:res);
}