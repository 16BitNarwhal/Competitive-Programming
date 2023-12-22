// maximum subarray sum
// O (N) time
#include <iostream>
#include <algorithm>
using namespace std;

const int MxN= 3e4+1;
int arr[MxN];
int kadane(int n) {
    int currentMax = -MxN, totalMax = -MxN;
    for(int i=0;i<n;i++) {
        currentMax = max(currentMax,0) + arr[i];
        totalMax = max(totalMax, currentMax);
    }
    return totalMax;
}

int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<< kadane(n) <<endl;
    // maximum subarray circle
    /*
    int max1 = kadane(n), max2 = 0;
    for(int i=0;i<n;i++) {
        max2 += arr[i];
        arr[i] = -arr[i];
    }
    max2 += kadane(n);
    cout<< max(max1,max2) << endl;
    */
}