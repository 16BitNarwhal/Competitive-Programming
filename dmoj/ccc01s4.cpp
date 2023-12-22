#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld n, x[10], y[10];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin>>x[i]>>y[i];
    ld ans=0;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            for (int k=j+1;k<n;k++) {
                ld dax=x[i]-x[j],day=y[i]-y[j],dbx=x[i]-x[k],dby=y[i]-y[k],dcx=x[j]-x[k],dcy=y[j]-y[k],
                    a=sqrt(dax*dax+day*day),b=sqrt(dbx*dbx+dby*dby),c=sqrt(dcx*dcx+dcy*dcy),
                    semi=(a+b+c)/2, area=sqrt(semi*(semi-a)*(semi-b)*(semi-c)), r=a*b*c/(4*area);
                ld s[3] = {a,b,c};
                sort(s,s+3);
                // inside circle
                if(s[0]*s[0]+s[1]*s[1]<s[2]*s[2])
                    ans = max(ans, s[2]/2);
                else // requires circumradius
                    ans = max(ans, r);
            }
        }
    }
    cout << setprecision(2) << fixed;
    cout << ans*2;
} 