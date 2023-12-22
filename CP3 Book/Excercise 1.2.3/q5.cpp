#include <bits/stdc++.h>
using namespace std;

struct date {
    int day, month, year;
};

bool cmp(date a, date b) {
    if(a.month != b.month) return a.month < b.month;
    if(a.day != b.day) return a.day < b.day;
    return a.year < b.year;
}

const int N = 1e5;
date ar[N];

int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>ar[i].day>>ar[i].month>>ar[i].year;
    sort(ar, ar+n, cmp);
    cout<<"\n";
    for(int i=0;i<n;i++) 
        cout<<ar[i].day<<" "<<ar[i].month<<" "<<ar[i].year<<"\n";
}