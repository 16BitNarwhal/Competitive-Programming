#include <bits/stdc++.h>
using namespace std;
const int n=10;
void permutate(char ar[], int j) {
    if(j<n)
        for(int i=j;i<n;i++) {
            swap(ar[i], ar[j]);
            permutate(ar, j+1);
            swap(ar[i], ar[j]);
        }
    else {
        /* 
        // RUN THIS ONLY WITH n <= 7
        for(int i=0;i<n;i++)
            printf("%c", ar[i]);
        printf("\n");
        */
    }
}
int main() {
    char letters[n];
    for(int i=0;i<n;i++) {
        letters[i] = (char)('A'+i);
    }
    permutate(letters, 0);
    printf("Finished\n");
}