class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> v(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            v[row][col] = dist;
            int dRow[] = {-1, 0, 1, 0};
            int dCol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                    !vis[nRow][nCol]) {
                    q.push({{nRow, nCol}, dist + 1});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        return v;
    }
};