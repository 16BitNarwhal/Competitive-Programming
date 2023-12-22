#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+2;
struct decor { int l, r, v; };
bool cmp(decor a, decor b) { return a.l < b.l; }
int N, L, S;
vector<decor> vec;
bool intersect(decor a, decor b) { return (a.r >= b.l && a.l <= b.r); }
int main() {
    cin >> N >> L >> S;
    vec.resize(N);
    for (int i=0;i<N;i++) {
        cin >> vec[i].l >> vec[i].r >> vec[i].v;
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i=1;i<vec.size();i++) { 
        if (intersect(vec[i-1], vec[i])) {
            int e[4];
            e[0] = min(vec[i-1].l, vec[i].l);
            e[1] = max(vec[i-1].l, vec[i].l);
            e[2] = min(vec[i-1].r, vec[i].r);
            e[3] = max(vec[i-1].r, vec[i].r);
            int leftval = (vec[i-1].l < vec[i].l ? vec[i-1].v : vec[i].v);
            int rightval = (vec[i-1].r > vec[i].r ? vec[i-1].v : vec[i].v);
            int midval = vec[i-1].v + vec[i].v;
            vec[i-1].l = e[0], vec[i-1].r = e[1]-1, vec[i-1].v = leftval;
            vec[i].l = e[2]+1, vec[i].r = e[3], vec[i].v = rightval;
            if (vec[i-1].l > vec[i-1].r) {
                vec.erase(vec.begin()+i-1);
                i--;
            }
            if (vec[i].l > vec[i].r) {
                vec.erase(vec.begin()+i);
            }
            decor a; a.l = e[1], a.r = e[2], a.v = midval;
            vec.insert(vec.begin()+i, a);
            cout << vec[i].l << ' ' << vec[i].r << '\n';
        }
    }
    int ans = L;
    for (int i=0;i<vec.size();i++) {
        cout << vec[i].l << ' ' << vec[i].r << ' ' << vec[i].v << '\n';
        if (vec[i].v >= S) 
            ans -= (vec[i].r - vec[i].l + 1);
    }
    cout << ans << '\n';
}