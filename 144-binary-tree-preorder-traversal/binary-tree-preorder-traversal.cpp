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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* node = root;
        while(node) {
            if(node->left == NULL) {
                v.push_back(node->val);
                node = node->right;
            }
            else {
                TreeNode* prev = node->left;
                while(prev->right && prev->right != node)
                    prev = prev->right;
                if(prev->right == NULL) {
                    prev->right = node;
                    v.push_back(node->val);
                    node = node->left;
                }
                else {
                    prev->right = NULL;
                    node = node->right;
                }
            }
        }
        return v;
    }
};