/*
As an example, consider a problem where we are given a list of n numbers
and a number x, and we want to find out if it is possible to choose some numbers
from the list so that their sum is x. For example, given the list [2,4,5,9] and
x = 15, we can choose the numbers [2,4,9] to get 2+4+9 = 15. However, if x = 10
for the same list, it is not possible to form the sum.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> get_sum(vector<int> ar) {
    int n = ar.size();
    vector<int> ret(1<<n);
    for(int b=0;b<(1<<n);b++) { 
        for(int i=0;i<n;i++) 
            if(b&(1<<i)) ret[b] += ar[i];
    }
    return ret;
}

int main() {
    int n,x;cin>>n>>x;
    vector<int> a(n/2), b(n-(n/2));
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    a = get_sum(a);
    b = get_sum(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(auto i:a) {
        if(i>x) break;
        for(auto j:b) {
            if(i+j>x) break;
            if(i+j==x) {
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
}