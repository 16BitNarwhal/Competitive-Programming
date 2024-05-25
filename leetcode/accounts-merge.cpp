class Solution {
public:

    vector<int> dsu;

    int root(int u) {
        if (dsu[u]==u) return u;
        return dsu[u] = root(dsu[u]);
    }

    void merge(int u, int v) {
        int ru = root(u);
        int rv = root(v);
        dsu[ru] = rv;
    }

    bool canMerge(vector<string>& a, vector<string>& b) {
        if (a[0] != b[0]) return false;
        for (int i=1,j=1;i<a.size() && j<b.size();) {
            if (a[i]==b[j]) return true;
            while (i<a.size() && a[i]<b[j]) i++;
            if (i==a.size()) break;
            while (j<b.size() && b[j]<a[i]) j++;
            if (j==b.size()) break;
        }
        return false;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (vector<string>& v : accounts) sort(v.begin()+1, v.end());
        
        int n = accounts.size();
        dsu.resize(n);
        for (int i=0;i<n;i++) dsu[i]=i;

        for (int i=0;i<n;i++) {
            for (int j=1;j<n;j++) {
                if (root(i) != root(j) &&
                    canMerge(accounts[i], accounts[j])) merge(i, j);
            }
        }
        
        vector<set<string>> res(n);
        set<pair<int,string>> uniques;
        for (int i=0;i<n;i++) {
            int r = root(i);
            uniques.insert({r, accounts[i][0]});
            for (int j=1;j<accounts[i].size();j++) 
                res[r].insert(accounts[i][j]);
        }

        vector<vector<string>> ans;
        for (auto [i, name] : uniques) {
            vector<string> cur;
            cur.push_back(name);
            for (string s : res[i]) 
                cur.push_back(s);
            ans.push_back(cur);
        }
        
        return ans;
    }
};