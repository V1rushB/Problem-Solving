class Solution {
private:
    int rows, cols;
    vector<int> dx = {1, 0, -1 , 0};
    vector<int> dy = {0, -1, 0, 1};

    void dfs(vector<vector<int>> &d, vector<vector<bool>> &visited, pair<int, int> node) {
        int x = node.first; int y = node.second;
        visited[x][y] = true;
        for(int o = 0; o < 4;o++) {
            int row = x + dx[o];
            int col = y + dy[o];

            if(row >= 0 && col >= 0 && row < rows && col < cols && !visited[row][col] && d[x][y] <= d[row][col]) {
                dfs(d, visited, make_pair(row, col));
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(); cols = heights[0].size();

        vector<vector<bool>> pacVisited(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlVisited(rows, vector<bool>(cols, false));

        for(int o = 0; o < cols;o++)
            dfs(heights, pacVisited, make_pair(0,o));
        
        for(int o = 0; o < rows;o++)
            dfs(heights, pacVisited, make_pair(o,0));

        for(int o = 0; o < cols;o++)
            dfs(heights, atlVisited, make_pair(rows-1,o));

        for(int o = 0; o < rows;o++)
            dfs(heights, atlVisited, make_pair(o, cols-1));

        vector<vector<int>> ans;
        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                if(atlVisited[o][i] == pacVisited[o][i] && atlVisited[o][i] == true) {
                    ans.push_back({o, i});
                }
            }
        }
        return ans;
    }
};

