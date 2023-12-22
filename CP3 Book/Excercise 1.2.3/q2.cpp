#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;

int main() {
    int n; double x;
    scanf("%i", &n);
    x = pow(10, n);
    x = round(PI * x) / x;
    printf("%.16g\n", x);
}