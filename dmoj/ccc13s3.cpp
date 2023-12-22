#include <bits/stdc++.h>
using namespace std;
const int MM = 10;
int T, G, ar[MM], id=1, ans;
pair<int,int> games[MM];
bool vis[MM][MM];

void rec(int game) {
    if (game==id) {
        for (int i=1;i<=4;i++) {
            if (i==T) continue;
            if (ar[i] >= ar[T]) return;
        }
        ans ++;
        return;
    }
    int a = games[game].first, b = games[game].second;
    game++;
    ar[a] += 3; rec(game); ar[a] -= 3;
    ar[b] += 3; rec(game); ar[b] -= 3;
    ar[a]++,ar[b]++; rec(game); ar[a]--,ar[b]--;
}

int main() {
    cin >> T >> G;
    for (int i=1,a,b,sa,sb;i<=G;i++) {
        cin >> a >> b >> sa >> sb;
        if (sa > sb) ar[a]+=3;
        else if (sa < sb) ar[b]+=3;
        else ar[a]++, ar[b]++;
        vis[a][b]=1;
    }
    for (int i=1;i<=4;i++) {
        for (int j=i+1;j<=4;j++) {
            if (!vis[i][j])
                games[id++] = {i,j};
        }
    }
    rec(1);
    cout << ans;
}