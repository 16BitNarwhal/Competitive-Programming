#include <bits/stdc++.h>
using namespace std;
int ar[101];
int main() {
  int n,a,b;
  cin >> n >> a >> b;
  if (b==0) {
    if (a!=0 && a+2>n) {
      cout << "-1\n"; 
    } else {
      ar[0] = ar[1] = 1;
      for (int i=2;i<a+2;i++) {
        ar[i] = ar[i-1] + 1;
      }
      for (int i=a+2;i<n;i++) {
        ar[i] = 1;
      }
      for (int i=0;i<n;i++) 
        cout << ar[i] << ' '; 
      cout << '\n';
    }
    return 0;
  }
  ar[0] = 1;
  int sum=ar[0];
  for (int i=1;i<b+1;i++) {
    ar[i] = sum+1;
    sum += ar[i]; 
  }
  for (int i=b+1;i<a+b+1;i++) {
    ar[i] = ar[i-1] + 1;
  }
  for (int i=a+b+1;i<n;i++) {
    ar[i] = 1;
  }
  for (int i=0;i<n;i++) {
    if (ar[i]>50000) {
      cout << "-1\n"; return 0;
    }
  }
  for (int i=0;i<n;i++) {
    cout << ar[i] << ' ';
  }
  cout << '\n'; 
}