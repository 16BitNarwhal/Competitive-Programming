/*
Page 52, Pruning the Search
Let us consider the problem of calculating the number of paths in an n × n
grid from the upper-left corner to the lower-right corner such that the path visits
each square exactly once. 
*/

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
typedef vector<bool> vb;
long long calls = 0;
int n;
vector<vb> g;
long long res = 0;

bool check() {
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            if(!g[i][j]) return 0;
    return 1;
}

void search(int i, int j, int di, int dj) {
    calls++;
    if(i==n && j==n && check()) {
        res++;
        return;
    }
    if(di != 0) {
        if(g[i+di][j] && !g[i][j-1] && !g[i][j+1])
            return;
    } else {
        if(g[i][j+dj] && !g[i-1][j] && !g[i+1][j])
            return;
    }
    if(!g[i-1][j]) {
        g[i-1][j] = 1;
        search(i-1, j, -1, 0);
        g[i-1][j] = 0;
    }
    if(!g[i+1][j]) {
        g[i+1][j] = 1;
        search(i+1, j, 1, 0);
        g[i+1][j] = 0;
    }
    if(!g[i][j-1]) {
        g[i][j-1] = 1;
        search(i, j-1, 0, -1);
        g[i][j-1] = 0;
    }
    if(!g[i][j+1]) {
        g[i][j+1] = 1;
        search(i, j+1, 0, 1);
        g[i][j+1] = 0;
    }
}

int main() {
    cin>>n;
    g.resize(n+2, vb(n+2,0));
    for(int i=0;i<n+2;i++) 
        g[i][0] = g[0][i] = g[i][n+1] = g[n+1][i] = 1;

    // start time
    auto t1 = chrono::high_resolution_clock::now();
    // function to measure
    g[1][1] = g[1][2] = 1;
    search(1, 2, 0, 1);
    res *= 2;
    // end time
    auto t2 = chrono::high_resolution_clock::now();

    cout<<res<<"\n";

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    cout<<"Execution time (ms) : " <<duration<<"\n";
    cout<<"Recursive calls : " <<calls<<"\n";
}

/*
Input (max) : 7
Result : 111712
Execution time (ms): 15712 (15s)
Recursive calls : 81778047 (81 billion)
*/