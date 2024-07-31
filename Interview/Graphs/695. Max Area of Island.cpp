class Solution {
private:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    int row, col;

    int bfs(const vector<vector<int>> &d, vector<vector<bool>> &visited, pair<int,int> pt) {
        visited[pt.first][pt.second] = true;
        int temp(0);
        for(int o = 0; o < 4;o++) {
            int x = dx[o] + pt.second;
            int y = dy[o] + pt.first;

            if(x >= 0 && y >= 0 && x < col && y < row) {
                if(d[y][x] == 1) {
                    if(!visited[y][x]) {
                        temp += 1 + bfs(d, visited, make_pair(y,x));
                    }
                }
            }
        }
        return temp;

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        row = grid.size();
        col = grid[0].size();
        int mx(0);
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int o = 0; o < row;o++) {
            for(int i = 0; i < col;i++) {
                if(grid[o][i] == 1 && !visited[o][i]) {
                    mx = max(mx, 1 + bfs(grid, visited, make_pair(o,i)));
                }
            }
        }
        return mx;
    }
};

