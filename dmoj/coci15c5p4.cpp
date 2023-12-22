#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1000002;

int main() {
    ll n, x;
    cin>>n>>x;
    if((n-2)*(n-1)/2 < x) {
        cout<<-1<<'\n';
        return 0;
    }
    vector<int> unused;
    cout<<n<<' '; n--;
    for(int i=1;i<n;i++) {
        if(x<n-i) {
            unused.push_back(i); 
        } else {
            x -= (n-i);
            cout<<i<<' ';
        }
    }
    cout<<n<<' ';
    for(int i=unused.size()-1;i>=0;i--) cout<<unused[i]<<' ';
        
}