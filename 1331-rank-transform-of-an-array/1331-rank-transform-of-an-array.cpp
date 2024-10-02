class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> sorted = arr;
        int cnt = 0;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] > sorted[i - 1])
                cnt++;
            mp[sorted[i]] = cnt;
        }
        for (int i = 0; i < arr.size(); i++)
            sorted[i] = mp[arr[i]];
        return sorted;
    }
};