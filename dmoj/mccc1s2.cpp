#include <bits/stdc++.h>
using namespace std;
const int MM=2e3+2;
int n; bool ar[MM][MM];
vector<int> r, c;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin>>ar[i][j];
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if(ar[i][j]!=ar[1][j]) {
                r.push_back(i);
                for (int k=1;k<=n;k++) 
                    ar[i][k] = !ar[i][k];  
                break;
            }
        }
    } 
    for (int j=1;j<=n;j++) {
        for (int i=1;i<=n;i++) {
            if(ar[i][j]) {
                c.push_back(j);
                for (int k=1;k<=n;k++)
                    ar[k][j] = !ar[k][j]; 
                break;
            }
        }
    }
    bool flag=1; 
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) { 
            if (ar[i][j]) {
                flag=0; 
            }
        } if(!flag) break; 
    }
    if (flag) {
        cout << r.size() + c.size() << '\n'; 
        for (int i:r) cout <<"R "<<i<<"\n";
        for (int i:c) cout <<"C "<<i<<"\n";
    } else cout <<-1<<'\n';

}