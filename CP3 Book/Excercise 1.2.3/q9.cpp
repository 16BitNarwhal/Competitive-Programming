#include <bits/stdc++.h>
using namespace std;

int convert_to_dec(string a, int base) {
    int res = 0, mult = 1;
    for(int i=a.length()-1;i>=0;i--) {
        if(a[i] >= '0' && a[i] <= '9') {
            res += (int)(a[i]-'0')*mult;
        } else {
            res += ((int)(a[i]-'A')+10)*mult;
        }
        mult *= base;
    }
    return res;
}
string convert_from_dec(int a, int base) {
    string res = "";
    while(a) {
        res = to_string(a%base) + res;
        a /= base;
    }
    return res;
}

int main() {
    string inp; int b1, b2;
    cin>>inp>>b1>>b2;
    cout<<convert_from_dec(convert_to_dec(inp, b1), b2)<<"\n";
}