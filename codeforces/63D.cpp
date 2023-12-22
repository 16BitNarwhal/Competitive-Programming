#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pi;
char grid[110][110];
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  queue<pi> q;
  pi pos = (b&1 ? pi(1, b) : pi(a, b));
  int m = a*b + c*d;
  q.push(pos);
  while (q.size() < m) {
    if (pos.y & 1) {
      if (pos.x == a) {
        pos.y--;
      } else {
        pos.x++;
      }
    } else {
      if (pos.x == 1) {
        pos.y--;
      } else {
        pos.x--;
      }
    }
    q.push(pos);
    if (pos.y == 1 && pos.x == a) break;
  }
  while (q.size() < m) {
    if (pos.y & 1) {
      if (pos.x == a+c) {
        pos.y++;
      } else {
        pos.x++;
      }
    } else {
      if (pos.x == a+1) {
        pos.y++;
      } else {
        pos.x--;
      }
    }
    q.push(pos);
  }
  memset(grid, '.', sizeof grid);
  int n;cin>>n;
  for (int i=0;i<n;i++) {
    int cnt;cin>>cnt;
    char c = (char)(i+'a');
    while (cnt--) {
      pi p = q.front();
      q.pop();
      grid[p.x][p.y] = c;
    }
  }
  cout << "YES\n";
  for (int i=1;i<=max(b,d);i++) {
    for (int j=1;j<=a+c;j++) 
      cout << grid[j][i];
    cout << endl;
  }
}