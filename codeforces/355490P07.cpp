#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c) {
  set<int> s = {'a', 'e', 'i', 'o', 'u', 'y'};
  return s.find(c) != s.end();
}
void toLower(char &c) {
  if (c >= 'A' && c <= 'Z') {
    c += 'a' - 'A';
  }
}
int main() {
  string s;cin>>s;
  string res="";
  for (char c : s) {
    toLower(c);
    if (!isVowel(c)) {
      res += ".";
      res += c;
    }
  }
  cout << res << '\n';
}