class Solution {
    int row, col, INF = INT_MAX;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        for(int o = 0; o < row;o++) {
            for(int i = 0; i < col;i++) {
                if(!grid[o][i]) {
                    q.push(make_pair(o, i));
                }
            }
        }

        while(!q.empty()) {
            auto pt = q.front(); q.pop();
            for(int o = 0; o < 4;o++) {
                int x = pt.first + dx[o];
                int y = pt.second + dy[o];

                if(x >=0 && y >= 0 && x < row && y < col && grid[x][y] == INF) {
                    grid[x][y] = grid[pt.first][pt.second] + 1; 
                    q.push(make_pair(x, y));
                }
            }
        }
    }
};

