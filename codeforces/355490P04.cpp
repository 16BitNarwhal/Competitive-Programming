#include <bits/stdc++.h>
using namespace std;
void tolower(char &c) {
  if (c >= 'A' && c <= 'Z') {
    c += 'a' - 'A';
  }
}
int main() { 
  string a,b; 
  cin >> a >> b;
  int n = a.length();
  for (int i=0;i<n;i++) tolower(a[i]);
  for (int i=0;i<n;i++) tolower(b[i]);
  if (a < b) cout << "-1\n";
  else if (a==b) cout << "0\n";
  else cout << "1\n";
}