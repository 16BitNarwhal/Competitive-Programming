/*
Let us now consider another version of the coin problem where our task is to
calculate the total number of ways to produce a sum x using the coins. For
example, if coins = {1,3,4} and x = 5, there are a total of 6 ways:
*/
#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int> coins, dp;

int main() {
    cin>>n>>x;
    coins.resize(n);
    for(auto &c:coins)cin>>c;
    dp.resize(x+1, 0);
    dp[0] = 1;
    for(int i=1;i<=x;i++)
        for(int c:coins)
            if(i>=c) dp[i] += dp[i-c];

    cout<<dp[x]<<"\n";
}