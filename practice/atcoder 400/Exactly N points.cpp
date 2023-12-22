// https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> ar;
    while(n>0) {
        ar.push_back(1);
        n--; 
        for(int i=0;i<ar.size() && n>0;i++) {
            ar[i]++;
            n--;
        }
    }
    for(auto i:ar) cout<<i<<"\n";
}