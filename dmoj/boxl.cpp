#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
struct event { int x, yl, yh, v; };
int n, m, bit[3*MM], cnt, ans;
vector<event> vec; 
map<int, int> mp;
bool cmp(event a, event b) { return a.x < b.x || a.x == b.x && a.v > b.v; }
void update(int pos, int val) {
    for (int i=pos; i<=cnt; i+=i&-i) bit[i] += val;
}
int query(int pos) {
    int sum = 0;
    for (int i=pos; i>0; i-=i&-i) sum += bit[i];
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i=1, x1, x2, y1, y2; i<=n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < x2 && y1 < y2) {
            vec.push_back(event{x1, y1, y2, 1});
            vec.push_back(event{x2, y1, y2, -1});
            mp[y1] = mp[y2] = 0;
        }
    }
    for (int i=1, x, y; i<=m; i++) {
        cin >> x >> y;
        vec.push_back(event{x, y, y, 0});
        mp[y] = 0;
    }
    for (auto &y : mp) y.second = ++cnt;
    sort(vec.begin(), vec.end(), cmp);
    for (event e : vec) {
        if (e.v != 0) {
            int lo = mp[e.yl], hi = mp[e.yh];
            update(lo, e.v); update(hi+1, -e.v);
        } else if (query(mp[e.yl]) > 0) {
            ans++;
        }
        
    }
    cout << ans;
    
}