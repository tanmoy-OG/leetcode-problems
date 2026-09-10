class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1 && !vis[i][0])
                dfs(grid, vis, i, 0);
            if(grid[i][n-1] == 1 && !vis[i][n-1])
                dfs(grid, vis, i, n-1);
        }
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1 && !vis[0][j])
                dfs(grid, vis, 0, j);
            if(grid[m-1][j] == 1 && !vis[m-1][j])
                dfs(grid, vis, m-1, j);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1 && !vis[i][j])
                    cnt++;
        return cnt;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        if(grid[i][j] == 0) {
            vis[i][j] = 1;
            return;
        }
        int m = grid.size(), n = grid[0].size();
        vis[i][j] = 1;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
            int row = i + dRow[k];
            int col = j + dCol[k];
            if(row >= 0 && row < m && col >= 0 && col < n && !vis[row][col])
                dfs(grid, vis, row, col);
        }
    }
};