class Solution {
    int rows, cols;


    bool dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited, int parent) {
        visited[val] = true;

        for(int el : mp[val]) {
            if(!visited[el]) {
                if(!dfs(el, mp, visited, val)) {
                    return false;
                }
            } else {
                if(parent != el) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        rows = edges.size();
        vector<bool> visited(n, false);
        for(int o = 0; o < rows;o++) {
            int u = edges[o][0];
            int v = edges[o][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        if(!dfs(0, mp, visited, -1)) {
            return false;
        }

        for(auto el : visited) {
            if(!el)
                return el;
        }
        return true;
    }
};

