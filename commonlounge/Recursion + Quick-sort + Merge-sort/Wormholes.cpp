#include <iostream>     
#include <algorithm>   
#include <vector>
#include <climits>

using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
        if (arr[m] <= x && arr[m+1] > x){
            return m;
        }
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int binarySearch2(vector<int> arr, int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
        if (arr[m] >= x && arr[m-1] < x){
            return m;
        }
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main() {
    bool con1 = true, con2 = true;
    int n,x,y,ans = INT_MAX;
    cin >> n >> x >> y;
    vector<int> s(n),e(n);
    vector<int> v(x),w(y);
    int a,b;

    for(int i = 0;i < n;i++)
        cin >> s[i] >> e[i];
    for(int i = 0;i < x;i++)
        cin >> v[i];
    for(int i = 0;i < y;i++)
        cin >> w[i];

    sort(v.begin(),v.end());
    sort(w.begin(),w.end());

    for(int i=0; i<n; i++) {
        int o = binarySearch(v,0,x-1,s[i]);
        if(o == -1) {
            if(v[x-1] <= s[i])
                o = x-1;
            else {
                o = 0;
                con2 = false;
            }
        }
        int p = binarySearch2(w,0,y-1,e[i]);
        if(p == -1) {
            if(w[0] >= e[i])
                p = 0;
            else{
                p = y-1;
                con1 = false;
            }
        }
        if(con1 && con2) 
            ans = min(ans,abs(w[p] - v[o] + 1));
        con1 = true; con2 = true;
    }
    cout << ans;
}
/*
3 4 2
15 21
5 10
7 25
4 14 25 2
13 21
*/