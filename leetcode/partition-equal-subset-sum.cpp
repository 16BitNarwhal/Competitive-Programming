class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int x:nums)sum+=x;
        if (sum%2==1) return false;
        int target=sum/2;
        vector<int> dp(100*200+1, 0);
        dp[0]=1;
        for (int x:nums) {
            for (int i=target;i>=x;i--) {
                dp[i] |= dp[i-x];
            }
        }
        return dp[target];
    }
};