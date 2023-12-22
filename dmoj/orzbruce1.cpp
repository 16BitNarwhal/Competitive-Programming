#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double hrs = (a/1000/40) + (b/1000/60) + (c/1000/70);
    double min = hrs*60;
    cout << fixed << setprecision(2) << min;
}