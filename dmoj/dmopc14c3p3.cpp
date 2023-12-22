#include <bits/stdc++.h>
using namespace std;

struct foo {
    int val, id;
    string name;
    
    bool operator<(const foo &o) {
        if(val==o.val) return id<o.id;
        return val<o.val;
    }
};

foo a[505];
int main() {
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i].name>>a[i].val;
        a[i].id = i;
    }
    sort(a,a+n);
    cin>>m;
    for(int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        y += x;
        for(int j=0;j<n;j++) {
            if(a[j].val >= x && a[j].val <= y) {
                cout<<a[j].name<<'\n';
                goto q;
            }
        }
        cout<<"No suitable teacher!\n";
        q:;
    }
}