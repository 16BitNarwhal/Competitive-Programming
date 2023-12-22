#include <bits/stdc++.h>
using namespace std;

int s,n;
struct foo {
    int i,b,d,c;
};

bool cmp(foo l, foo r) {
    if(l.b == r.b) { 
        if(l.b >= s) return l.c > r.c;
        else if(l.b < s) return l.d > r.d;
        return l.i > r.i;
    }
    return l.b > r.b;
}

int main() {
    cin>>s>>n;
    vector<foo> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].b>>v[i].d>>v[i].c;
        v[i].i = i;
    }
    sort(v.begin(), v.end(), cmp);
    int q;cin>>q;
    while(q--) {
        int x;cin>>x;
        cout<<v[x-1].i+1<<'\n';
    }
    

}