class Solution {
private:
    int row, col;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    void dfs(vector<vector<char>> &d, vector<vector<bool>> &visited, pair<int, int> point) {
        visited[point.first][point.second] = true;
        for(int o = 0; o < 4;o++) {
            int x = point.first + dx[o];
            int y = point.second + dy[o];
            if(x >= 0 && y >= 0 && x < row && y < col && d[x][y] == '1' && !visited[x][y]) {
                dfs(d, visited, make_pair(x,y));
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int s(0);
        for(int o = 0; o < row;o++) {
            for(int i = 0; i < col;i++) {
                if(!visited[o][i] && grid[o][i] == '1') {
                    s++;
                    dfs(grid, visited, make_pair(o, i));
                }
            }
        }
        return s;
    }
};

