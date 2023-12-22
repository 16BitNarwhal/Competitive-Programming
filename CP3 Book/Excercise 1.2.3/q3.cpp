#include <bits/stdc++.h>
using namespace std;

// day = (dayofmonth + 13*(month+1)/5 + year%100 + (year%100)/4 + (year/100) - 2*(year/100))
unordered_map<string, int> convert_month = {
    {"January",13},{"February",14},{"March",3},{"April",4},{"May",5},{"June",6},
    {"July",7},{"August",8},{"September",9},{"October",10},{"November",11},{"December",12}
};
unordered_map<int, string> convert_day = {
    {1,"Sunday"},{2,"Monday"},{3,"Tuesday"},{4,"Wednesday"},{5,"Thursday"},{6,"Friday"},{0,"Saturday"}
};

int main() {
    int day, month, year, ans;
    string temp;
    cin>>day>>temp>>year;
    month = convert_month[temp];
    ans = day + (13*(month+1)/5) + (year%100) + (year%100)/4 + (year/100) - 2*(year/100);
    cout<<convert_day[(ans+6)%7]<<"\n";
}