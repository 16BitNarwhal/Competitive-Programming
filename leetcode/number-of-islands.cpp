#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int count=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (vis[i][j] || grid[i][j]=='0') continue;
                count += 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    q.pop();
                    if (vis[x][y] || grid[x][y]=='0') continue;
                    vis[x][y] = true;
                    if (x) q.push({x-1,y});
                    if (y) q.push({x, y-1});
                    if (x<m-1) q.push({x+1,y}); 
                    if (y<n-1) q.push({x,y+1});
                }
            }
        }
        return count;
    }
};