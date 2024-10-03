class Solution {
private:
    int rows, cols;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        int s(0);
        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                if(grid[o][i] == 2) {
                    q.push(make_pair(o, i));
                }
            }
        }
        
        while(!q.empty()) {
            auto pt = q.front(); q.pop();
            for(int o = 0; o < 4;o++) {
                int row = pt.first + dx[o];
                int col = pt.second + dy[o];

                if(row >= 0 && col >= 0 && row < rows && col < cols && grid[row][col] == 1 && !dist[row][col]) {
                    grid[row][col] = 2;
                    dist[row][col] = 1 + dist[pt.first][pt.second];
                    q.push(make_pair(row, col));
                }
            }
        }
        int mx = 0;
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                if(grid[o][i] == 1) {
                    return -1;
                }
                mx = max(mx, dist[o][i]);
            }
        }
        return mx;
    }
};

