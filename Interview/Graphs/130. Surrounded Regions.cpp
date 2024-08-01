class Solution {
private:
    int rows;
    int cols
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,-1,0,1};

    bool dfs(int row, int col, const vector<vector<int>> &d, vector<vector<bool>> &visited, int depth) {
        if(row < 0 || col < 0 || visiited[row][col] || row >= rows || cols >= cols || depth > 1)
            return 0;
        visited[row][col] = true;
        bool ok = true;
        for(int o =0; o < 4;o++) {
            int x = row + dx[o];
            int y = col + dy[o];
            if(d[x][y] == 'X')
                ok = ok && dfs(x,y,d,visited,depth+1);
            else {
                ok = ok && dfs(x,y,d,visited,depth+1);
            }
        }
        return ok;
    }

    

public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visisted(rows, vector<int>(cols,false));

        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {

            }
        }
    }
};
