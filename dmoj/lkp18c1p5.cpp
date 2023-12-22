#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef vector<int> vi;
struct node { int l, r, lz; vi f; } seg[3*MM];
int N, M, K;