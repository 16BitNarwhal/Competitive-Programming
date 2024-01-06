#include <bits/stdc++.h>
using namespace std;

int check(int n, vector<int> a) {
    vector<int> best1, best2;
    int mn=1e9;
    for (int i=0;i<(1<<n);i++) {
        vector<int> b1, b2;
        for (int j=0;j<n;j++) {
            if (i&(1<<j)) {
              b1.push_back(a[j]);
            } else {
              b2.push_back(a[j]);
            }
        }
        int cnt=0;
        for (int k=1;k<b1.size();k++) {
            cnt += (b1[k] > b1[k-1]);
        }
        for (int k=1;k<b2.size();k++) {
            cnt += (b2[k] > b2[k-1]);
        }
        if (cnt < mn) {
          mn = cnt;
          best1 = b1;
          best2 = b2;
        }
        // if (cnt==3) {
        //   for (int x:b1) cout << x << ' '; cout << " | ";
        //   for (int x:b2) cout << x << ' '; cout << '\n';
        // }
    }
    for (int x:best1) cout << x << ' '; cout << " | ";
    for (int x:best2) cout << x << ' '; cout << '\n';
    return mn;
}

int main() {
  int t;cin>>t;
  while (t--) {
    int n;cin>>n;
    vector<int> a(n);
    for (int &x:a) cin>>x;
    cout << check(n, a) << '\n';
    reverse(a.begin(), a.end());
    vector<int> d(n+1, 1e9);
    vector<int> argd(n+1, -1);
    vector<int> p(n+1, -1);
    d[0] = -1e9;
    for (int i=0;i<n;i++) {
      int l =upper_bound(d.begin(), d.end(), a[i]) - d.begin();
      if (d[l-1] < a[i] && a[i] < d[l]) {
        d[l] = a[i];
        argd[l] = i;
        p[i] = argd[l-1];
      }
    }
    int lis=0;
    for (int i=0;i<=n;i++) {
      if (d[i] < 1e9) lis = i;
    }
    int cur = argd[lis];
    vector<int> ans1, ans2;
    vector<int> used(n, 0);
    used[cur] = 1;
    while (cur != -1) {
      ans1.push_back(a[cur]);
      cur = p[cur];
      used[cur] = 1;
    }
    for (int i=0;i<n;i++) {
      if (!used[i]) ans2.push_back(a[i]);
    }
    reverse(ans2.begin(), ans2.end());
    int cnt=0;
    for (int i=1;i<ans1.size();i++) {
      cnt += (ans1[i] > ans1[i-1]);
    }
    for (int i=1;i<ans2.size();i++) {
      cnt += (ans2[i] > ans2[i-1]);
    }
    for (int x:ans1) cout << x << ' '; cout << " | ";
    for (int x:ans2) cout << x << ' '; cout << '\n';
    cout << cnt << '\n';
  }
}
