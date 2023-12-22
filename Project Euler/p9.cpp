#include <bits/stdc++.h>
using namespace std;

int main() {
    for(int a=1;a<1000;a++) {
        for(int b=1;b<1000;b++) {
            int x = a*a + b*b;
            int c = sqrt(x);
            if(x==c*c && a + b + c == 1000) {
                cout<<a<<" "<<b<<" "<<c<<"\n";
            }
        }
    }
}