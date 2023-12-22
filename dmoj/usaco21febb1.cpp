#include <bits/stdc++.h>
using namespace std;

map<string, int> mp = {{"Ox",0},{"Tiger",1},{"Rabbit",2},{"Dragon",3},
                        {"Snake",4},{"Horse",5},{"Goat",6},{"Monkey",7},
                        {"Rooster",8},{"Dog",9},{"Pig",10},{"Rat",11}};
map<string, int> names={{"Bessie",0}};
int main() { 
    int n;cin>>n;
    while(n--) {
        string a, b, op, yr, tmp;
        cin >> a >>tmp>>tmp>> op >> yr >> tmp>>tmp >> b;
        if (op=="previous") {
            names[a] = mp[yr];
            while(names[a]<names[b]) names[a]+=12;
            while(names[a]>=names[b]) names[a]-=12;
        } else {
            names[a] = mp[yr];
            while(names[a]>names[b]) names[a]-=12;
            while(names[a]<=names[b]) names[a]+=12;
        }
    }
    // for (auto i:names) cout<<i.first<<' ' <<i.second<<'\n';
    cout << abs(names["Elsie"] - names["Bessie"]) << '\n';
}

// Ox, Tiger, Rabbit, Dragon, Snake, Horse, 
// Goat Monkey, Rooster, Dog, Pig, Rat
