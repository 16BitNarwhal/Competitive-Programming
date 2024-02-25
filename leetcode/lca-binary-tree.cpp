#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    stack<TreeNode*> reverse(stack<TreeNode*> st) {
        stack<TreeNode*> cpy = st;
        stack<TreeNode*> ret;
        while (!cpy.empty()) {
            ret.push(cpy.top());
            cpy.pop();
        }
        return ret;
    }

    stack<TreeNode*> running;
    stack<TreeNode*> p_ancestors, q_ancestors;
    void rec(TreeNode* cur, TreeNode* p, TreeNode* q) {
        running.push(cur);
        if (cur->val == p->val) {
            p_ancestors = reverse(running);
        } else if (cur->val == q->val) {
            q_ancestors = reverse(running);
        }
        if (cur->left != nullptr) rec(cur->left, p, q);
        if (cur->right != nullptr) rec(cur->right, p, q);
        running.pop();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root, p, q);
        TreeNode* ans = new TreeNode(0);
        while (!p_ancestors.empty() && !q_ancestors.empty()) {
            if (p_ancestors.top()->val == q_ancestors.top()->val) {
                ans = p_ancestors.top();
                p_ancestors.pop();
                q_ancestors.pop();
            } else {
                break;
            }
        }
        return ans;
    }
};