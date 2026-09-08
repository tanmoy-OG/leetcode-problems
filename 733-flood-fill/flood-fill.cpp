class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int check = image[sr][sc];
        if (check == color)
            return image;
        int m = image.size(), n = image[0].size();
        vector<vector<int>> v = image;
        dfs(v, m, n, sr, sc, color, check);
        return v;
    }
    void dfs(vector<vector<int>>& v, int& m, int& n, int row, int col, int& color, int& check) {
        if(v[row][col] != check)
            return;
        v[row][col] = color;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n)
                dfs(v, m, n, nRow, nCol, color, check);
        }
    }
};