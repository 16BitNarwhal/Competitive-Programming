#include <bits/stdc++.h>
using namespace std;
int n = 100;

int main() {
    long long sum = 0;
    n--;
    for(int i=1;i<=n/3;i++)
        sum += i*3;
    for(int i=1;i<=n/5;i++) 
        sum += i*5;
    for(int i=1;i<=n/15;i++)
        sum -= i*15;
        
    cout<<sum<<"\n";
}