class Solution {
private:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int o = 0; o < rows; o++) {
            for (int i = 0; i < cols; i++) {
                if (!grid[o][i]) {
                    q.push({o, i});
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int o = 0; o < 4;o++) {
                int x = row + dx[o];
                int y = col + dy[o];
                
                if (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == INT_MAX) {
                    grid[x][y] = grid[row][col] + 1;
                    q.push({x, y});
                }
            }
        }
    }
};
