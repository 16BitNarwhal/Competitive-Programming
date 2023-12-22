#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;
        vector<int> res;
        int a, b;
        if (target%2==0 && mp[target/2]>=2) {
            a=b=target/2;
        } else {
            for (int x : nums) {
                if (x!=target/2 && mp[target-x]) {
                    a=x; b=target-x;
                    break;
                }
            }
        }
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==a || nums[i]==b) 
                res.push_back(i);
            if (res.size()==2) return res;
        }
        return res;
    }
};