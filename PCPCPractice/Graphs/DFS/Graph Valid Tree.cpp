class Solution {
private:
    int rows, cols;
    bool dfs(int val, int parent, map<int, vector<int>> &mp, vector<bool> &visited) {
        visited[val] = true;

        for(auto el : mp[val]) {
            if(!visited[el]) {
                if(!dfs(el, val, mp, visited)) {
                    return false;
                }
            } else {
                if(el != parent) {
                    return false;
                }
            }
        }
        return true;

    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        map<int, vector<int>> mp;
        for(int o = 0; o < edges.size();o++) {
            int u = edges[o][0];
            int v = edges[o][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        if(!dfs(0, -1, mp, visited))
            return false;

        for(auto el : visited)
            if(!el)
                return false;
        return true; 
    }
};

