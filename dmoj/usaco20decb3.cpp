#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+1;
struct cow {
    int time_stop=INF, x, y;
    char dir; 
};
int N;
cow ar[50];
// cow i hit cow j going North
int hit(int i, int j, int t) {
    cow I = ar[i], J = ar[j];
    if (I.dir==J.dir) return INF;
    // since theoretical, swap x,y to switch orientation
    if (I.dir=='E') { swap(I.x, I.y); swap(J.x, J.y); } // i move up, j move right
    if (J.y <= I.y) return INF;
    if (J.time_stop == INF) {
        if (I.x < J.x-t || I.x >= J.x + J.y - I.y)
            return INF; // no intersection
    } else {
        if (I.x < J.x-J.time_stop || I.x > J.x)
            return INF; // no intersection
    }
    return J.y + t - I.y;
}
int next(int t) {
  int T[50], minT = INF; 
  for (int i=0; i<N; i++) {
    T[i] = INF;
    if (ar[i].time_stop == INF) {
      for (int j=0; j<N; j++)
        T[i] = min(T[i], hit(i, j, t));
      minT = min(minT, T[i]);
    }
  }
  if (minT==INF) return INF;
  for (int i=0; i<N; i++) {
    if (ar[i].time_stop == INF) {
      if (ar[i].dir == 'N') ar[i].y += (minT - t);
      else ar[i].x += (minT - t);
    }
    if (T[i]==minT) ar[i].time_stop = minT;
  }
  return minT;
}
int main() {
    cin >> N;
    for (int i=0;i<N;i++) 
        cin >> ar[i].dir >> ar[i].x >> ar[i].y;
    int t=0;
    do {
        t = next(t);
    } while (t != INF);
    for (int i=0;i<N;i++) {
        if (ar[i].time_stop==INF) cout<<"Infinity\n";
        else cout << ar[i].time_stop << '\n';
    }
}