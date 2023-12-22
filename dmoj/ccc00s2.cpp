#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<double> a(n);
    for(auto &i:a) cin>>i;
    while(1) {
        int buf;cin>>buf;
        if(buf==99) {
            int id; 
            double x; 
            cin>>id>>x;
            id--;
            x = a[id]*x/100;
            a.insert(a.begin()+id+1, a[id]-x);
            a[id] = x;
        } else if(buf==88) {
            int id; cin>>id;
            if(id==a.size()) continue;
            id--;
            a[id] += a[id+1];
            a.erase(a.begin()+id+1);
        } else break;
    }
    for(auto i:a) cout<<i<<' '; cout<<'\n';
}