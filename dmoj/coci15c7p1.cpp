#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;cin>>s;
  string indent = "";
  for (int i=0;i<s.length();i++) {
    char c = s[i];
    if (c=='{') {
      cout << "{";
      indent += "  ";
      if (s[i+1] != '}') cout << "\n" << indent;
    } else if (c=='}') {
      indent.erase(indent.length()-2, 2);
      cout << "\n" << indent << "}";
    } else if (c==',') {
      cout << ",\n" << indent;
    } else {
      cout << c;
    }
  }
  cout << '\n';
}