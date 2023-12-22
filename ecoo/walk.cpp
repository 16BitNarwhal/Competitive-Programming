#include <bits/stdc++.h>
using namespace std;
set<pair<int,int>> sol;
pair<int,int> Q(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    pair<int,int> ret; 
    cin >> ret.first >> ret.second; 
    return ret;
}
int main() {
    for (int i=-10;i<=10;i++) {
        for (int j=-10;j<=10;j++) {
            pair<int,int> q = Q(i,j);
            sol.insert(q);
        }
    }
    cout << "! "<<sol.size();
}