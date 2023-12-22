#include <bits/stdc++.h>
using namespace std;

vector<string> words;
void split_string(string s) {
    string word = "";
    for(auto c:s) {
        if(c==' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);
}
bool isNum(char c) {
    return (c>='0' && c<='9');
}
int main() {
    string s;
    getline(cin, s);
    split_string(s);
    for(string word : words) {
        if(word.length()==3 && islower(word[0]) 
            && isNum(word[1]) && isNum(word[2])) 
            cout<<"*** ";
        else
            cout<<word<<" ";
    }
    cout<<"\n";
}