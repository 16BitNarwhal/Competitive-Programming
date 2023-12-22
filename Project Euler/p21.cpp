#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int divs(int x) {
    int sum = 0;
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            sum += i;
            if(i*i!=x && i!=1) sum += x/i;
        }
    }
    return sum;
}

int main() {
    ll res = 0;
    for(int i=1;i<10000;i++) {
        int x = divs(i);
        if(i == divs(x) && i != x) {
            cout<<i<<" "<<x<<"\n";
            res += i;
        }
    }
    cout<<res<<"\n";
}

// 31626