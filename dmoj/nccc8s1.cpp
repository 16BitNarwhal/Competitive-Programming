#include <bits/stdc++.h>
using namespace std;
string a, b;
set<string> res;
int main() {
    cin >> a >> b;
    for (int i=0;i<(int)a.size();i++) {
        for (int j=0;j<(int)b.size();j++) {
            b.insert(b.begin()+j, a[i]);
            res.insert(b);
            b.erase(b.begin()+j);
            char tmp = b[j];
            b[j] = a[i];
            res.insert(b);
            b[j] = tmp;
        }
        b.push_back(a[i]);
        res.insert(b);
        b.pop_back();
    }
    for (int i=0;i<(int)b.size();i++) {
        char tmp = b[i];
        b.erase(b.begin()+i);
        res.insert(b);
        b.insert(b.begin()+i, tmp);
    }
    for (string s:res) if(s!=b) cout<<s<<'\n';
}