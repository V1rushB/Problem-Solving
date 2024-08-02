class Solution {
private:
    int rows;

    void dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited) {
        visited[val] = true;

        for(int el : mp[val]) {
            if(!visited[el]) {
                dfs(el, mp,visited);
            }
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        rows = edges.size();
        map<int, vector<int>> mp;
        for(int o = 0; o < rows;o++) {
            int u = edges[o][0];
            int v = edges[o][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int s(0);
        for(int o = 0; o < n;o++) {
            if(!visited[o]) {
                s++;
                dfs(o,mp,visited);
            }
        }
        return s;
    }
};

