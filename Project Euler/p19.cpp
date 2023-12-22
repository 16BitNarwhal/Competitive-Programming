#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int,int> month2day = { 
  {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},
  {9,30},{10,31},{11,30},{12,31}
};

int main() {
  int year, month, day, dayOfWeek=2, count=0;
  for(year=1901;year<=2000;year++) {
    for(month=1;month<=12;month++) {
      if(month==2 && year%4==0) month2day[2]++;
      for(day=1;day<=month2day[month];day++) {
        dayOfWeek++;
        dayOfWeek %= 7;
        if(dayOfWeek==0 && day==1) count++;
      }
      if(month==2 && year%4==0) month2day[2]--;
    }
  }
  cout<<count<<"\n";
}