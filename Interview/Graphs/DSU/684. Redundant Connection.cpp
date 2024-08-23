class Solution {
private:
    int n, m;

    int Find(int val, vector<int> &parent) {
        int node = parent[val];
        while(node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool Union(int e1, int e2, vector<int> &parent, vector<int> &rank) {
        int p1 = Find(e1, parent);
        int p2 = Find(e2, parent);
        if(!(p1 - p2))
            return false;
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1]+=rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2]+=rank[p1];
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size(), m = edges[0].size();
        vector<int> parent(n+1), rank(n+1, 1);
        for(int o = 1; o <= n;o++)
            parent[o] = o;
        for(int o = 0; o < n;o++) {
                int u = edges[o][0];
                int v = edges[o][1];
                if(!Union(u,v, parent, rank))
                    return vector<int>{u,v};
        }
        return {};
    }
};

