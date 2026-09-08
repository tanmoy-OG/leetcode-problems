class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int check = image[sr][sc];
        if (check == color)
            return image;
        int m = image.size(), n = image[0].size();
        vector<vector<int>> v = image;
        queue<pair<pair<int, int>, int>> q;
        v[sr][sc] = color;
        q.push({{sr, sc}, color});
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currColor = q.front().second;
            q.pop();
            if (currColor == color) {
                int dRow[] = {-1, 0, 1, 0};
                int dCol[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int nRow = row + dRow[i];
                    int nCol = col + dCol[i];
                    if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                        v[nRow][nCol] == check) {
                        q.push({{nRow, nCol}, color});
                        v[nRow][nCol] = color;
                    }
                }
            }
        }
        return v;
    }
};