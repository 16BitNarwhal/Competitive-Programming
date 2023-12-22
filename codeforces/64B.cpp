#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;cin>>s;
  int pos = s.find('+');
  char op = '+';
  if (pos == string::npos) {
    pos = s.find('-');
    op = '-';
  }
  int a = stoi(s.substr(0, pos));
  int b = stoi(s.substr(pos+1, s.length()));
  if (op=='+') {
    cout << a + b << '\n';
  } else {
    cout << a - b << '\n';
  }
}