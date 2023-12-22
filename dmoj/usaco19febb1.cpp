#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout); 
  vector<int> cows(3);
	for (int i = 0; i < 3; i++) {
		cin >> cows[i];
	}
  sort(cows.begin(), cows.end());
  if (cows[0] == cows[1]+1 && cows[1] == cows[2]+1) {
    cout << 0;
  } else if (cows[0]+2 == cows[1] || cows[1]+2 == cows[2]) {
    cout << 1;
  } else {
    cout << 2;
  }
  cout << '\n';
  cout << max(cows[1] - cows[0] - 1, cows[2] - cows[1] - 1) << '\n';
}