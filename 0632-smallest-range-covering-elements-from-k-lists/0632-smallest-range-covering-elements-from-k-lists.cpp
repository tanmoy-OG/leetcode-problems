class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        int maxEle = INT_MIN;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEle = max(maxEle, nums[i][0]);
        }

        vector<int> ans = {-1000000, 1000000};

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listInd = curr[1];
            int ind = curr[2];

            if (maxEle - minEl < ans[1] - ans[0]) {
                ans[0] = minEl;
                ans[1] = maxEle;
            }

            if (ind + 1 < nums[listInd].size()) {
                int nextEle = nums[listInd][ind + 1];
                pq.push({nextEle, listInd, ind + 1});
                maxEle = max(maxEle, nextEle);
            } else {
                break;
            }
        }

        return ans;
    }
};