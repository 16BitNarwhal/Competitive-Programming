/*
Many scheduling problems can be solved using greedy algorithms. A classic
problem is as follows: Given n events with their starting and ending times, find a
schedule that includes as many events as possible. It is not possible to select an
event partially.
*/
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

bool cmp(const pair<int,int> a, const pair<int,int> b) {
    if(a.S != b.S) return a.S<b.S;
    return a.F<b.F;
}

int main() {
    int n;cin>>n;
    vector<pair<int,int>> a(n);
    for(auto &i:a) 
        cin>>i.F>>i.S;
    sort(a.begin(), a.end(), cmp);
    int res=1;
    auto lastPair = a[0];
    for(int i=1;i<n;i++) {
        if(lastPair.S<=a[i].F) {
            lastPair = a[i];
            res++;
        }
    }
    cout<<res<<"\n";
}

// Greedy (choose by earliest ending)