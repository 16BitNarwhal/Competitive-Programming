/*
Let us now consider a problem where we are given n tasks with durations and
deadlines and our task is to choose an order to perform the tasks. For each task,
we earn d − x points where d is the task’s deadline and x is the moment when we
finish the task. What is the largest possible total score we can obtain?
*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

int main() {
    int n;cin>>n;
    vector<pair<int,int>> tasks(n);
    for(auto &task:tasks) cin>>task.F>>task.S;
    sort(tasks.begin(), tasks.end());
    int res = 0, time = 0;
    for(int i=0;i<n;i++) {
        time += tasks[i].F;
        res += tasks[i].S - time;
    }
    cout<<res<<"\n";
}