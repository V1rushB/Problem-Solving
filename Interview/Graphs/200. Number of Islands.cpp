class Solution {
private:
    const int dx[4]{1, 0, -1, 0};
    const int dy[4]{0, 1, 0, -1};
    int row, col;

    void bfs(const vector<vector<char>> &d, vector<vector<bool>> &visited, pair<int,int> pt) {
        visited[pt.first][pt.second] = true;
        for(int o = 0; o < 4;o++) {
            int x = dx[o] + pt.second;
            int y = dy[o] + pt.first;
            if(x >= 0 && y >= 0 && x  < col && y < row && d[y][x] == '1' && !visited[y][x]) {
                bfs(d, visited, make_pair(y,x));
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int s(0);
        if(!grid.size())
            return 0;
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col,false));
        for(int o = 0; o < row;o++) {
            for(int i = 0; i < col;i++) {
                if(grid[o][i] == '1' && !visited[o][i]) {
                    s++;
                    bfs(grid, visited, make_pair(o,i));
                }
            }
        }
        return s;
    }
};

