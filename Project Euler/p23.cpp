#include <bits/stdc++.h>
using namespace std;

int divs(int x) {
    int sum = 0;
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            sum += i;;
            if(i!=x/i && i!=1) 
                sum += x/i;
        }
    }
    return sum;
}

int main() {
    vector<int> d;
    for(int i=1;i<=28123;i++)
        if(divs(i)>i) d.push_back(i);
    bool ar[28124];
    memset(ar, 0, 28124);
    cout<<"test\n";
    for(int i=0;i<d.size();i++) 
        for(int j=i;j<d.size();j++) 
            if(d[i]+d[j] <= 28123) ar[d[i]+d[j]] = 1;
    int sum = 0;
    for(int i=1;i<=28123;i++)
        if(ar[i]) sum += i;
    cout<<sum<<"\n";
}