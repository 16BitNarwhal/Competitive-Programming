#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n)); 
        queue<tuple<int,int,int>> q;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 2) q.push({i,j,0});
            }
        }
        int mx=0;
        vector<int> dirs = { 0, 1, 0, -1, 0 };
        while (!q.empty()) {
            int x = get<0>(q.front()), y = get<1>(q.front());
            int t = get<2>(q.front());
            q.pop();
            mx = max(mx, t);
            for (int i=0;i<4;i++) {
                if (x+dirs[i] < m && x+dirs[i] >= 0 &&
                    y+dirs[i+1] < n && y+dirs[i+1] >= 0) {
                        if (vis[x+dirs[i]][y+dirs[i+1]]) continue;
                        if (grid[x+dirs[i]][y+dirs[i+1]] != 1) continue;
                        q.push({x+dirs[i], y+dirs[i+1], t+1});
                        vis[x+dirs[i]][y+dirs[i+1]] = true;
                    }
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return mx;
    }
};