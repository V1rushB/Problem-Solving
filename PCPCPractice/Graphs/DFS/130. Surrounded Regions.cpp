class Solution {
private:
    int rows, cols;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};

    void dfs(pair<int, int> node, vector<vector<char>> &d, vector<vector<bool>> &visited) {
        int x = node.first; int y = node.second;
        if(x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y] || d[x][y] == 'X')
            return;
        
        visited[x][y] = true;
        for(int o = 0; o < 4;o++) {
            int rows = x + dx[o];
            int cols = y + dy[o];
            dfs(make_pair(rows, cols), d, visited);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int o = 0; o < cols;o++) {
            dfs(make_pair(0, o), board, visited);
            dfs(make_pair(rows-1, o), board, visited);
        }

        for(int o = 0; o < rows;o++) {
            dfs(make_pair(o, 0), board, visited);
            dfs(make_pair(o, cols-1), board, visited);
        }

        for(int o = 0; o < rows;o++) {
            for(int i = 0; i < cols;i++) {
                if(!visited[o][i] && board[o][i] == 'O')
                    board[o][i] = 'X';
            }
        }
    }
};

