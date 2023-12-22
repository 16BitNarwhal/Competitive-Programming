#include <bits/stdc++.h>
using namespace std;
// int n = 4e6;

int main() {
    int t;cin>>t;
    while(t--) {
        long long sum = 0, sum2 = 0;
        int a=1,b=1;
        int n;cin>>n;
        while(b <= n) {
            a += b;
            swap(a,b);
            sum2 += a;
            if(a % 2 ==0) 
                sum += a;
        }
        cout<<sum<<" "<<sum2<<"\n";
    }
}