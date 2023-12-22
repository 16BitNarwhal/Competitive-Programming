// 
#include <bits/stdc++.h>
using namespace std;
const int n = 20;
int help[n];

void subset(vector<int> ar, int i) {
    if(i<n) {
        subset(ar, i+1);
        ar.push_back(help[i]);
        subset(ar, i+1);
    } else {
        /* 
        // RUN THIS ONLY WITH n <= 10
        for(auto k:ar) printf("%i ", k);
        printf("\n");
        */

    }
}

int main() {
    for(int i=0;i<n;i++) help[i] = i;
    vector<int> ar;
    subset(ar, 0);
    printf("Finished\n");
}