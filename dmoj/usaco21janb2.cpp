#include <bits/stdc++.h>
using namespace std;

int n,e,o;
int main() {
    e=o=0;
    cin>>n;
    for(int i=0,x;i<n;i++) {
        cin>>x;
        if(x&1) o++;
        else e++;
    }
    int x = min(e,max(o,1))*2 + o;
    if(x%3==0) cout<<x/3*2;
    else if(x%3==2) cout<<x/3*2+1;
    else cout<<max(x/3*2-1,0);
}