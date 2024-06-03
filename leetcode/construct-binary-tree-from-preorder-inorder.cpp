/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> in;
        int n = inorder.size();
        for (int i=0;i<n;i++) in[inorder[i]] = i;
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i=1;i<n;i++) {
            TreeNode* cur = root;
            while (true) {
                if (in[preorder[i]] < in[cur->val]) {
                    if (cur->left==nullptr) {
                        cur->left = new TreeNode(preorder[i]);
                        break;
                    }
                    cur = cur->left;
                } else {
                    if (cur->right==nullptr) {
                        cur->right = new TreeNode(preorder[i]);
                        break;
                    }
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};