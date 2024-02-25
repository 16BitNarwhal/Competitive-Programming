class Solution {
public:
    vector<int> merge_two(const vector<int>& a, const vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    bool intersect(const vector<int>& a, const vector<int>& b) {
        return a[1]>=b[0] && b[1]>=a[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> cur = intervals[0];
        for (vector<int> v : intervals) {
            if (intersect(cur, v)) {
                cur = merge_two(cur, v);
            } else {
                res.push_back(cur);
                cur = v;
            }
        }
        if (res.size()==0 || !intersect(res.back(), cur)) {
            res.push_back(cur);
        }
        return res;
    }
};