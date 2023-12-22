// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int t; cin>>t;
//     while(t--) {
//         int n;cin>>n;
//         if(n<192) cout<<"192\n";
//         else {
//             n = (n-192)/250;
//             cout<<192+(n+1)*250<<"\n";
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        while (++n) {
            if (n*n*n % 1000 == 888) {
                cout << n << '\n';
                break;
            }
        }
    }
}