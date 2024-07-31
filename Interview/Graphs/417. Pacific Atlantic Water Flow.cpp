class Solution {
private:
    int rows;
    int cols;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>> &visited, int prev, const vector<vector<int>> &heights) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || visited[row][col] || heights[row][col] < prev)
            return;
        visited[row][col] = true;

        for (int o = 0; o < 4; o++) {
            int x = row + dx[o];
            int y = col + dy[o];
            dfs(x, y, visited, heights[row][col], heights);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<int>> pac(rows, vector<int>(cols, 0));
        vector<vector<int>> atl(rows, vector<int>(cols, 0));

        for (int o = 0; o < cols; o++) {
            dfs(0, o, pac, heights[0][o], heights);
            dfs(rows - 1, o, atl, heights[rows - 1][o], heights);
        }

        for (int o = 0; o < rows; o++) {
            dfs(o, 0, pac, heights[o][0], heights);
            dfs(o, cols - 1, atl, heights[o][cols - 1], heights);
        }

        vector<vector<int>> ans;

        for (int o = 0; o < rows; o++) {
            for (int i = 0; i < cols; i++) {
                if (atl[o][i] && pac[o][i]) {
                    ans.push_back(vector<int>{o, i});
                }
            }
        }

        return ans;
    }
};
