class Solution {
    int row, col;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};

    int dfs(vector<vector<int>> &d, vector<vector<bool>> &visited, pair<int, int> pt) {
        visited[pt.first][pt.second] = true;
        int temp = 1;
        for(int o = 0; o < 4;o++) {
            int x = pt.first + dx[o];
            int y = pt.second + dy[o];
            if(x >= 0 && y >= 0 && x < row && y < col && d[x][y] == 1 && !visited[x][y]) {
                temp += dfs(d, visited, make_pair(x, y));
            }
        }
        return temp;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        int mx = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int o = 0; o < row;o++) {
            for(int i = 0; i < col;i++) {
                if(grid[o][i] == 1 && !visited[o][i]) {
                    mx = max(mx, dfs(grid, visited, make_pair(o, i)));
                }
            }
        }
        return mx;
    }
};

