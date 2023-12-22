#include <bits/stdc++.h>
using namespace std;

int n;
double a[10001], memo[10001];
double cost(int i) {
    if(memo[i]!=0) return memo[i];
    if(i>=n) return 0;
    double ret = a[i] + cost(i+1);
    if(i+1<n) {
        ret = min(ret, a[i]+a[i+1] - (min(a[i],a[i+1])/2.0) + cost(i+2));
        if(i+2<n) 
        ret = min(ret, a[i]+a[i+1]+a[i+2] - min(min(a[i],a[i+1]),a[i+2]) + cost(i+3));
    }
    return memo[i]=ret;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    printf("%.1f", cost(0));
}