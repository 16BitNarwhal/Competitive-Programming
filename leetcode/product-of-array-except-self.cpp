#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pfx(nums.size()), sfx(nums.size());
        for (int i=0;i<nums.size();i++) {
            pfx[i] = nums[i];
            if (i) pfx[i] *= pfx[i-1];
        }
        for (int i=nums.size()-1;i>=0;i--) {
            sfx[i] = nums[i];
            if (i<nums.size()-1) sfx[i] *= sfx[i+1];
        }
        vector<int> ans(nums.size());
        for (int i=0;i<nums.size();i++) {
            ans[i] = 1;
            if (i) ans[i] *= pfx[i-1];
            if (i<nums.size()-1) ans[i] *= sfx[i+1];
        }
        return ans;
    }
};