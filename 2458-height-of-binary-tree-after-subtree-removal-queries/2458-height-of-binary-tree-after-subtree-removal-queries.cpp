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
    int getHeight(TreeNode* root, int lev, vector<pair<int, int>>& level,
                  vector<pair<int, int>>& maxHeights) {
        if (root == nullptr)
            return 0;
        int left = getHeight(root->left, lev + 1, level, maxHeights);
        int right = getHeight(root->right, lev + 1, level, maxHeights);
        int currentHeight = max(left, right) + 1;

        level[root->val] = {lev, currentHeight};

        auto& [firstMax, secondMax] = maxHeights[lev];
        if (currentHeight > firstMax) {
            secondMax = firstMax;
            firstMax = currentHeight;
        } else if (currentHeight >= secondMax) {
            secondMax = currentHeight;
        }

        return currentHeight;
    }

public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        const int MAX_LEVEL = 1e5 + 7;
        vector<pair<int, int>> level(MAX_LEVEL);
        vector<pair<int, int>> maxHeights(MAX_LEVEL, {0, 0});
        int maxH = getHeight(root, 0, level, maxHeights);
        vector<int> ans;
        for (auto& it : queries) {
            int nodeHeight = level[it].second;
            int i = level[it].first;
            auto& [firstMax, secondMax] = maxHeights[i];
            int maxOtherHeight =
                (nodeHeight == firstMax && firstMax == secondMax)
                    ? firstMax
                    : (nodeHeight == firstMax ? secondMax : firstMax);

            ans.push_back(i + maxOtherHeight - 1);
        }

        return ans;
    }
};