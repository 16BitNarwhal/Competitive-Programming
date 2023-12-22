/*
Given a list of weights
[w1,w2,...,wn], determine all sums that can be constructed using the weights.
For example, if the weights are [1,3,3,5], the following sums are possible:
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    int n,m=0;cin>>n;
    vi w(n);
    for(auto &i:w) {
        cin>>i;
        m += i;
    }
    vector<bool> dp(m+1);
    dp[0] = 1;
    for(int k=0;k<n;k++)
        for(int x=m;x>=0;x--) 
            if(dp[x]) dp[x+w[k]] = 1;
    for(int i=1;i<=m;i++)
        cout<<dp[i]<<" ";

}