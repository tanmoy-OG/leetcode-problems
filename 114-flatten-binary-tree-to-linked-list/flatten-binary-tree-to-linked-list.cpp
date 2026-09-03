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
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        fill(root, q);
        q.push(NULL);
        while(q.front()) {
            TreeNode* node = q.front();
            q.pop();
            node->left = NULL;
            node->right = q.front();
        }
    }
    void fill(TreeNode* node, queue<TreeNode*>& q) {
        if(!node)
            return;
        q.push(node);
        fill(node->left, q);
        fill(node->right, q);
    }
};