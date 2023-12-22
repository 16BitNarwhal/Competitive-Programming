#include <bits/stdc++.h>
using namespace std;

string cow,s;
int main() {
    cin>>cow>>s;
    int c=0;
    deque<char> q;
    for(char c:s) q.push_front(c);
    while(!q.empty()) { 
        for(int i=0;i<26;i++)
            if(q.back()==cow[i])
                q.pop_back(); 
        c++;
    }
    cout<<c;
}