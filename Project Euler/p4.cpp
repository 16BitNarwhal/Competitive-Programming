#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int mult=1;
    while(mult*10 < x)
        mult *= 10;
    
    while(mult) {
        if( (x/mult)%10 != x%10 )
            return 0;
        x /= 10;
        mult /= 100;
    }
    return 1;
}
int main() {
    int mx=0;
    for(int i=1;i<1000;i++) {
        for(int j=1;j<1000;j++) {
            if(isPalindrome(i*j)) {
                mx = max(mx, i*j);
            }
        }
    }
    cout<<mx<<"\n";
}