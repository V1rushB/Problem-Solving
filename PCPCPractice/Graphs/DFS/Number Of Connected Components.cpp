class Solution {
private:

    void dfs(int val, map<int, vector<int>> &mp, vector<bool> &visited) {
        visited[val] = true;

        for(auto el : mp[val]) {
            if(!visited[el])
                dfs(el, mp, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        map<int, vector<int>> mp;
        for(int o = 0; o < edges.size();o++) {
            int u = edges[o][0];
            int v = edges[o][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int s(0);
        for(int o = 0; o < n;o++) {
            if(!visited[o]) {
                s++;
                dfs(o, mp, visited);
            }
        }
        return s;
    }
};

