class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < isConnected.size(); i++)
            if(!vis[i]) {
                dfs(i, isConnected, vis);
                cnt++;
            }
        return cnt;
    }
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[i] = 1;
        for(int j = 0; j < isConnected.size(); j++)
            if(i != j && isConnected[i][j] && !vis[j])
                dfs(j, isConnected, vis);
    }
};