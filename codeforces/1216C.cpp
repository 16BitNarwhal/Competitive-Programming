#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
struct rect { ll x1,y1,x2,y2; };
rect intersect(rect a, rect b) { 
    rect res;
    res.x1 = max(a.x1, b.x1);
    res.x2 = min(a.x2, b.x2);
    res.y1 = max(a.y1, b.y1);
    res.y2 = min(a.y2, b.y2);
    return res;
} 
ll area(rect a) {
    return max(a.x2-a.x1,0LL)*max(a.y2-a.y1,0LL);
}
int main() { 
    rect w, b1, b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    rect a1 = intersect(w, b1), a2 = intersect(w, b2);
    rect aa = intersect(a1, a2);
    if (area(a1) + area(a2) - area(aa) == area(w)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}