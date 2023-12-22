#include <bits/stdc++.h>
using namespace std;

struct stand {
    int id,dist;
    friend bool operator<(const stand &a, const stand &b) {
        return a.dist > b.dist;
    }
};

int dists[100005];
bool apples[100005][105];
priority_queue<stand> pq[100005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,s;
    cin>>n>>s;
    for(int i=1,d;i<=n;i++) {
        cin>>d;
        dists[i] = d;
    }
    
    for(int i=1,j,a;i<=s;i++) {
        cin>>j>>a;
        apples[j][a]=1;
        stand stnd; stnd.id = j; stnd.dist = dists[j];
        pq[a].push(stnd);
    }
    int q;cin>>q;
    while(q--) {
        char o;cin>>o;
        int x,k;
        if(o=='A') {
            cin>>x>>k;
            apples[x][k] = 1;
            stand stnd; stnd.id = x; stnd.dist = dists[x];
            pq[k].push(stnd);
        } else if(o=='S') {
            cin>>x>>k;
            apples[x][k] = 0;
        } else if(o=='E') {
            cin>>x>>k;
            dists[x] = k;
            memset(apples[x], 0, sizeof(apples[x]));
        } else {
            cin>>k;
            if(!pq[k].empty()) {
                stand t = pq[k].top();
                // distance was changed
                while(t.dist != dists[t.id]) {
                    pq[k].pop();
                    stand stnd; stnd.id = t.id; stnd.dist = dists[t.id];
                    pq[k].push(stnd);
                    t = pq[k].top();
                }
                // apple no longer sells
                while(!pq[k].empty() && !apples[t.id][k]) {
                    pq[k].pop();
                    t = pq[k].top();
                }
                
                if(pq[k].empty()) cout<<"-1\n";
                else cout<<t.id<<'\n';
            } else
                cout<<"-1\n";
        }
    }
}