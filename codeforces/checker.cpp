#include<bits/stdc++.h>
using namespace std;

int n, a[101], c_correct[101], c_inp[101];
int readAns(ifstream &fin) {
  for (int i=0;i<n;i++) {
    fin >> a[i];
  }
  for (int i=0;i<n;i++) c_inp[i] = 0;
  for (int i=1;i<=n;i++) {
    sort(a, a+i);
    for (int j=0;j<n;j++) {
      c_inp[j] += a[j];
    }
  }
  for (int i=0;i<n;i++) {
    if (c_inp[i] != c_correct[i]) return 0;
  }
  return 1;
}
int main(int argc, char * argv[]){
  ifstream fin("input_file", ifstream::in);
  ifstream ans("myAnswer", ifstream::in);
  ifstream cor("correctAnswer", ifstream::in);
  int t; fin>>t;
  fin>>n;
  for (int i=0;i<n;i++) fin >> c_correct[i];
  if (readAns(ans)==0) {
    cout << "Wrong Answer\n";
    return -1;
  }
  return 0;
}