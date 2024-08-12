typedef pair<int,int> pi;

class Solution {
    int rows, cols;
    int glcost = -1;
    
    bool dfs(int val, vector<bool> &visited, map<int,vector<pi>> &mp, int parent, int depth, int k, int cost, int dest) {
        if(depth > k) {
            return false;
        }
        if(val == dest) {
            glcost = cost; 
            return true;
        }

        visited[val] = true;

        bool ok = false;
        for(auto el : mp[val]) {
            int nextNode = el.first;
            int newCost = el.second;
            if(!visited[nextNode]) {
                if(dfs(nextNode, visited, mp, val, depth + 1, k, cost + newCost, dest)) {
                    ok = true;
                }
            } else {
                if(nextNode != parent) {
                    return false;
                }
            }
        }
        visited[val] = false;
        return ok;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        rows = flights.size();
        cols = flights[0].size();
        vector<bool> visited(n, false);

        map<int, vector<pi>> mp;

        for(int o = 0; o < rows;o++) {
            int src = flights[o][0];
            int dest = flights[o][1];
            int cost = flights[o][2];
            mp[src].push_back(make_pair(dest,cost));
        }
        if(!dfs(src, visited, mp, -1, -1, k, 0, dst)) {
            return -1;
        }
        return glcost;
    }
};

