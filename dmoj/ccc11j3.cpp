#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,res=1;cin>>a>>b;
    while(b>=0) { 
        a -= b;
        swap(a,b);
        res++;
    }
    cout << res;
} 