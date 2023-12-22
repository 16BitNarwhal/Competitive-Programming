/*
Given a set
of coin values coins = {c1, c2,..., ck} and a target sum of money n, our task is to
form the sum n using as few coins as possible.
*/
#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> coins, dp;

int main() {
    cin>>n>>x;
    coins.resize(n);
    dp.resize(x+1, x);
    for(auto &i:coins)cin>>i;
    dp[0] = 0;
    vector<int> first(n+1);
    for(int i=1;i<=x;i++) 
        for(int c : coins) 
            if(i>=c)
                dp[i] = min(dp[i], dp[i-c]+1); 

    cout<<dp[x]<<"\n";

}