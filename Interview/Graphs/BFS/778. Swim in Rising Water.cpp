typedef pair<int,pair<int,int>> pii;

class Solution {
private:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};
    int rows, cols;

public:
    int swimInWater(vector<vector<int>>& grid) {
        rows = grid.size(); cols = grid[0].size();

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(grid[0][0], make_pair(0,0)));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;
        while(!pq.empty()) {
            auto point = pq.top().second;
            auto waterLevel = pq.top().first;
            int x = point.first; int y = point.second;
            pq.pop();

            if(x == rows - 1 && y == cols - 1)
                return waterLevel;

            for(int o = 0; o < 4;o++) {
                int row = x + dx[o];
                int col = y + dy[o];
                if(row >= 0 && col >= 0 && row < rows && col < cols && !visited[row][col]) {
                    pq.push(make_pair(max(waterLevel, grid[row][col]), make_pair(row,col)));
                    visited[row][col] = true;
                }
            }
        }


    }
};