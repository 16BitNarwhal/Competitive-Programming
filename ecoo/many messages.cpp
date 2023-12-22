#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int cnt=0;
    while (cnt < 3) {
        a += b;
        cnt++;
        if (a>=c) {
            cout << a << '\n';
            return 0;
        }
    }
    cout<<"Who knows...\n";
    
}