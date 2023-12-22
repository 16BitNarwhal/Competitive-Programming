#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+2;
int N,K,a[MM],cnt[MM];
bool used[MM];
stack<int> st; 
vector<int> res;
int main() { 
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin >> a[i]; cnt[a[i]]++;  
    } 
    for (int i=0;i<N;i++) {
        if (!used[a[i]]) {
            while (!st.empty() && st.top()>a[i] 
                    && cnt[st.top()]) {
                used[st.top()]=0;
                st.pop();   
            }
            st.push(a[i]);
            used[a[i]]=1;
        }
        cnt[a[i]]--; 
    }
    while(!st.empty()) { 
        res.push_back(st.top()); 
        st.pop();
    } 
    for (int i=K-1;i>0;i--) cout << res[i] << ' ';
    cout << res[0] << '\n';
}