#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<set<multiset<int>>> dp(target+1);
        dp[0] = {{{0}}};
        for (int i=0;i<=target;i++) {
            for (int x : candidates) {
                if (i+x>target) continue;
                for (multiset<int> v : dp[i]) {
                    multiset<int> u = v;
                    u.insert(x);
                    dp[i+x].insert(u);
                }
            }
        }
        vector<vector<int>> res;
        for (multiset<int> s : dp[target]) {
            vector<int> cur;
            for (int x : s) {
                if (x != 0) cur.push_back(x);
            }
            res.push_back(cur);
        }
        return res;
    }
};