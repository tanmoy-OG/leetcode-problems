/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        dfs(root, 0, v);
        return v;
    }
    void dfs(TreeNode* node, int level, vector<int>& v) {
        if(!node)
            return;
        if(level == v.size())
            v.push_back(node->val);
        dfs(node->right, level+1, v);
        dfs(node->left, level+1, v);
    }
};