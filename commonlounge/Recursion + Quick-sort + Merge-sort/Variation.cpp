#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for(int i=0; i<N; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  int c=0;
  for(int i=0, j=1; i<N, j<N;) {
    cout << i << " " << j << " " << c << endl;
    if(abs(arr[i]-arr[j]) >= K) {
      c += N-j;
      i++;
    } else {
      j++;
    }
  }

  cout << c;  

}