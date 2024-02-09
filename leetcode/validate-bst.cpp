
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long long mn=((long long)INT_MIN)-1, long long mx=((long long)INT_MAX)+1) {
        bool valid = true;
        if (root->val <= mn || root->val >= mx) valid = false;
        if (root->left) valid &= isValidBST(root->left, mn, root->val);
        if (root->right) valid &= isValidBST(root->right, root->val, mx);
        return valid;
    }
};