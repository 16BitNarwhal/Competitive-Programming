#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ifstream file;
    file.open("t22.txt");
    char s[(int)1e6];
    file >> s;
    file.close();
    char *token = strtok(s, ",");
    vector<string> a;
    while(token != NULL) {
        a.push_back(token);
        token = strtok(NULL, ",");
    }
    sort(a.begin(), a.end());
    ll res = 0;
    for(int i=1;i<=a.size();i++) {
        int sum = 0;
        for(auto c : a[i-1])
            if(c!='"')
            sum += (int)(c-'A')+1;
        res += 1LL*sum*i;
    }
    cout<<res<<"\n";
}