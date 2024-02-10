class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums[0] == target) return 0;
        int l=1, r=nums.size()-1;
        while (l<=r) {
            int m = (l+r)/2;
            if (nums[0] <= nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (target > nums[0]) {
            r = l-1;
            l = 0;
        } else {
            r = nums.size()-1;
        }
        while (l<=r) {
            int m = (l+r)/2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m-1;
        }
        return -1;
    }
};