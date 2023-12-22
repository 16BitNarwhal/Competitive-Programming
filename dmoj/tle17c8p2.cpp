#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

pair<double,double> def[10];
double dmg[1010];

int main() {
    double h;
    int d,e;
    cin>>h>>d>>e;
    for(int i=0;i<d;i++) {
        cin>>def[i].F>>def[i].S;
        def[i].F /= 100.0;
    }
    
    for(int i=0,t,l,x;i<e;i++) {
        cin>>t>>l>>x;
        dmg[t] += x;
        dmg[t+l] -= x;
    }
    for(int i=0;i<1010;i++) {
        if(i>0) dmg[i] += dmg[i-1]; 
        double mn = dmg[i];
        for(int j=0;j<d;j++)
            mn = min(mn, (1.0 - def[j].F) * max(dmg[i]-def[j].S, 0.0));
        h -= mn;
        if(h<=0) break;
    }
    if(h<=0) cout<<"DO A BARREL ROLL!\n";
    else printf("%.2f\n", h);
}

