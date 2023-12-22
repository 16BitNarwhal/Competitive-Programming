#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int MM = 1e5+2;
int n, bit[MM]; double ans=0;
pi ar[MM]; // { val, order }
bool cmp(pi a, pi b) { return a.first==b.first?a.second>b.second:a.first>b.first; }

void insert(int x, int y) {
    for(int i=x;i<=n;i+=i&-i) bit[i] += y; 
}

int query(int x) { 
    int res=0; for(int i=x;i>0;i-=i&-i) res+=bit[i];
    return res;
}
 
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> ar[i].first;
        ar[i].second = i;
    }
    sort(ar+1, ar+n+1, cmp);
    for(int i=1;i<=n;i++) {
        insert(ar[i].second, 1);
        ans += query(ar[i].second);
    }
    printf("%.2f", ans/n);
}