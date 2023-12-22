#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> A(a), B(b), C(c);
  for(int i=0; i<a; i++) cin >> A[i];
  for(int i=0; i<b; i++) cin >> B[i];
  for(int i=0; i<c; i++) cin >> C[i];

  int tempA, tempB, tempC;
  int i=0,j=0,k=0;
  int total=0;
  int arr[50000];
  
  while(i<a || j<b || k<c) {
    if(i<a) tempA = A[i];
    else tempA = 2147483647;
    if(j<b) tempB = B[j];
    else tempB = 2147483647;
    if(k<c) tempC = C[k];
    else tempC = 2147483647;

    int smol = min(tempA, min(tempB, tempC));
    int c = 0;

    if(smol == tempA) { c++; i++; }
    if(smol == tempB) { c++; j++; }
    if(smol == tempC) { c++; k++; }

    if(c>=2) {
      arr[total] = smol; 
      total++;
    }
  }

  cout << total << endl;
  for(int i=0; i<total; i++) {
    cout << arr[i] << endl;
  }

}
/*
5 6 5
23 30 42 57 90 
21 23 35 57 90 92 
21 23 30 57 90 
*/