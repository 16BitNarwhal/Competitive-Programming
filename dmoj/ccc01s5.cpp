#include <bits/stdc++.h>
using namespace std;
const  int MM = 42;
int n, m, mxm;
string a[MM], b[MM];
stack<int> ans;
bool rec(string cura, string curb, int i, int c) {
    if (i!=-1) cura += a[i], curb += b[i];
    if (!cura.empty() && cura==curb) { 
        ans.push(i+1);
        return 1;
    }
    if (c>mxm) return 0;
    bool ret=0;
    for (int j=0;j<n;j++) {
        ret |= rec(cura, curb, j, c+1);
        if(ret) {
            if (i!=-1) ans.push(i+1);
            break;
        }
    }
    return ret;
}

int main() {
    cin >> m >> n; mxm = 40/n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    if (!rec("", "", -1, 0)) cout<<"No solution.\n";
    else {
        cout << ans.size() << '\n';
        while(!ans.empty()) {
            cout << ans.top() <<'\n';
            ans.pop();
        }
    }
}