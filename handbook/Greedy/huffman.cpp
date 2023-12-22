/*
Huffman coding is a greedy algorithm that constructs an optimal code for
compressing a given string. The algorithm builds a binary tree based on the
frequencies of the characters in the string, and each character’s codeword can be
read by following a path from the root to the corresponding node. A move to the
left corresponds to bit 0, and a move to the right corresponds to bit 1
*/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> pi;

bool cmp(const pi a, const pi b) {
    return a.S > b.S;
}

int main() {
    string s; cin>>s;
    vector<pi> v(26);   
    for(int i=0;i<26;i++) v[i].F = i, v[i].S = 0;
    for(char c : s) v[(int)(c-'A')].S++;
    sort(v.begin(), v.end(), cmp);
    vector<pair<char, string>> huff;
    string pre = "";
    for(int i=0;i<26;i++) {
        if(v[i].S>0) {
            huff.push_back({(char)(v[i].F+'A'),pre+'0'});
            pre += '1';
        } 
    }
    string tmp = huff.back().S;
    huff.back().S = tmp.substr(0, tmp.length()-1);
    unordered_map<char, string> mp;
    for(auto p : huff)
        mp[p.F] = p.S;
    string res = "";
    for(char c : s) 
        res += mp[c];
    cout<<res<<"\n";
}