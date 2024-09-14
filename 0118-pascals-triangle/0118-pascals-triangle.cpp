class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++)
            ans.push_back(generateRows(i));

        return ans;
    }
    vector<int> generateRows(int i) {
        long long value = 1;
        vector<int> response = {1};

        for (int j = 1; j < i; j++) {
            value *= i - j;
            value /= j;
            response.push_back(value);
        }

        return response;
    }
};