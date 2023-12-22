#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
int main() {
    double k, x, y;
    cin >> k >> x >> y;
    double mag = sqrt(x*x + y*y);
    if (mag==0) {
        cout<<"0 0\n";
        return 0;
    }
    double angle;
    if (x==0) {
        if (y>0) angle = 90;
        else angle = -90;
    } else {
        angle = atan2(y,x) * 180.0 / PI;
    }

    angle += k;
    if (angle > 180) angle -= 360;
    
    cout << mag << ' ' << angle << '\n';
    angle = angle / 180.0 * PI;
    x = mag * cos(angle);
    y = mag * sin(angle);

    cout << fixed;
    cout << x << ' ' << y << '\n';
}