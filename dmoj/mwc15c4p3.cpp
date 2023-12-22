#include <bits/stdc++.h>
using namespace std;
unordered_map<int,set<int>> X,Y;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0,x,y;i<n;i++) {
        cin>>x>>y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    for(int i=0,o;i<q;i++) {
        cin>>o;
        if(o==1) {
            int x,y;cin>>x>>y;
            cout<<(X.count(x)&&X[x].count(y)?"salty":"bland")<<'\n';
        }
        else {
            char c;int z;
            cin>>c>>z;
            cout<<(c=='X'? X[z].size() : Y[z].size()) <<'\n';
        }
    }
}