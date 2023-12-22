#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, H, c;
  cin >> N >> H;
  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];

  bool hold = false;
  int loc = 0;
  while(true) {
    cin >> c;
    if(c == 1 && loc > 0) {
      loc --;
    } else if(c == 2 && loc < N-1) {
      loc ++;
    } else if(c == 3 && !hold && arr[loc] > 0) {
      hold = true;
      arr[loc] --;
    } else if(c == 4 && hold && arr[loc] < H) {
      hold = false;
      arr[loc] ++;
    } else if(c == 0) {
      break;
    }
  }

  for(int i=0; i<N; i++)
    cout << arr[i] << " ";

}



/*
7 4
3 1 2 1 4 0 1
3 2 2 2 2 4 1 3 1 4 0
->
2 1 3 1 4 0 1
**********************
3 5
2 5 2
3 2 4 2 2 2 1 4 1 1 1 1 0
->
1 5 2 
*/