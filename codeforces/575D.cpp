#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 1000;
  cout << "2001\n";
  cout << "1 1 1 2\n";
  for (int i=1;i<=1000;i++)
    cout << i << " 1 " << i << " 2\n";
  for (int i=1000;i>=1;i--)
    cout << i << " 1 " << i << " 2\n";
}