/*
We next consider a problem where we are given n numbers a1,a2,...,an and our
task is to find a value x that minimizes the sum
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,c;cin>>n>>c;
    vector<int> a(n);
    for(auto &e:a) cin>>e;
    float x = 0;
    if(c==1) {
        // less than median is larger (than median)
        // greater than median is larger
        sort(a.begin(),a.end());
        x = n/2;
    } else if(c==2) {
        // (a1-x)^2+(a2-x)^2...
        // nx^2 - 2xs where s = (a1+a2...)
        // roots x = 0, 2s/n 
        // the min(vertex) of the parabola is at x = (0+2s)/n
        // x = s/n which is the average
        for(auto e:a) x+=e;
        x /= n;
    }
    cout<<x<<"\n";
}