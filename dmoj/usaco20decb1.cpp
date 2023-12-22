#include <bits/stdc++.h>
using namespace std;

int main() {
    int ar[7];
    for (int i=0;i<7;i++) cin>>ar[i];
    sort(ar, ar+7);
    cout << ar[0] << ' ' << ar[1] << ' ' << ar[6]-ar[0]-ar[1] << '\n';
}