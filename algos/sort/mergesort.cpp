#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k; 
    int n1 = m - l + 1;
    int n2 =  r - m;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i=0;i<n1;i++)
        L[i] = arr[l + i];
    for(int i=0;i<n2;i++)
        R[i] = arr[m + i + 1];
    
    i=0;j=0;k=l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void sort(vector<int>& arr, int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        sort(arr, l, m);
        sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i : arr) cout << i << " "; cout << endl;
    sort(arr, 0, n-1);
    for(int i : arr) cout << i << " "; cout << endl;
}