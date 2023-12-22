#include <bits/stdc++.h>
using namespace std;
const double prec = 1e-6;

double f(double x, int y) {
    double a=1;
    while(y--) a = pow(x, a);
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    int t_;scanf("%d", &t_);
    while(t_--) {
        int y,z; scanf("%d %d", &y, &z);
        double x,l=1,r=10;
        int c = 0;
        while(l+prec<r && c<48) {
            x = (l+r)/2;
            if(f(x,y)<z) l = x;
            else r = x;
            c++;
        }
        printf("%.6f\n", x);
    }
}