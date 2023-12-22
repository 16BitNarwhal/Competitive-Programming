#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkValidString(string s) {
    int x=0;
    int l=0,h=0;
    for(char i : s) {
        if(i=='(') x++;
        else x--;
        if(x<0) break;
        /*
        if(i=='(') l++;
        else l--;
        if(i!=')') h++;
        else h--;
        if(h<0) break;
        l = max(l, 0);
        */
    }
    return (!x);    
}

int main() {
    int t; cin>>t;
    while(t) {
    string s;
    cin >> s;
    if(checkValidString) cout << "Matching" << endl;
    else cout << "Not matching" << endl;
    t--;
    }
}