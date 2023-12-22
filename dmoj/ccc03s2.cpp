#include <bits/stdc++.h>
using namespace std;
unordered_map<char,bool> v = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
int main() {
    int t_;cin>>t_;
    scanf("%d\n",&t_);
    while(t_--) {
        string poem[4];
        for(int i=0;i<4;i++)
            getline(cin,poem[i]);
        for(int i=0;i<4;i++) {
            int n = poem[i].length();
            int st = 0;
            for(int j=0;j<n;j++) st = (poem[i][j]==' ') ? j : st;
            poem[i] = poem[i].substr(st,n-st);
            n = poem[i].length();

            for(int j=n-1;j>=0;j--) {
                poem[i][j] = tolower(poem[i][j]);
                if(v[poem[i][j]]) {
                    poem[i] = poem[i].substr(j,n-j); break;
                }
            }
        }
        if(poem[0]==poem[1] && poem[1]==poem[2] && poem[2]==poem[3]) cout<<"perfect\n";
        else if(poem[0]==poem[1] && poem[2]==poem[3]) cout<<"even\n";
        else if(poem[0]==poem[2] && poem[1]==poem[3]) cout<<"cross\n";
        else if(poem[0]==poem[3] && poem[1]==poem[2]) cout<<"shell\n";
        else cout<<"free\n";
    }
}