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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return NULL;

        queue<TreeNode*> q;

        q.push(root);
        root->val = 0;

        int currLevelSum = 0;

        while (!q.empty()) {
            int size = q.size();

            int nextLevelSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                curr->val = currLevelSum - curr->val;

                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                nextLevelSum += siblingSum;

                if (curr->left) {
                    curr->left->val = siblingSum;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = siblingSum;
                    q.push(curr->right);
                }
            }
            currLevelSum = nextLevelSum;
        }

        return root;
    }
};