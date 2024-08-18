class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int l=0,r=0,ans=0;
        for (;r<n;r++) {
            mp[s[r]]++;
            while (mp[s[r]]>1) mp[s[l++]]--;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};