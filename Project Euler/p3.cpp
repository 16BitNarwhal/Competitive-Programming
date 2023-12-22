#include <bits/stdc++.h>
using namespace std;
long long n = 600851475143;

void primeFactors() {  
    for(int i=sqrt(n);i>=1;i--) {
        if(n%i) {
            cout<<i<<"\n";
            break;
        }
    }
}

int main() {  
    int n = 1234567890;
    primeFactors();  
    return 0;  
} 