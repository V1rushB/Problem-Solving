#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define ll long long

class DSU {
private:
    vector<ll> parent, rank;

public:
    DSU(ll _size) {
        parent.resize(_size);
        rank.resize(_size, 1);
        for(int o = 0; o < _size;o++)
            parent[o] = o;
    }
    int Find(ll val) {
        ll node = parent[val];
        while(node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    void Union(ll e1, ll e2) {
        ll p1 = Find(e1);
        ll p2 = Find(e2);

        if(p1 == p2)
            return;
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
    }
};

void solution() {
    ll a; cin >> a;
    string str,str2; cin >> str >> str2;
    DSU dsu(26);

    for(int o = 0; o < a;o++)
        if(str[o] != str2[o])
            dsu.Union(str[o] -'a', str2[o] - 'a');

    map<char, vector<char>> mp;
    for(int o = 0; o < 26;o++) {
        mp[dsu.Find(o)+'a'].push_back(o+'a');
    }

    vector<pair<char,char>> ans;
    for(auto el : mp) {
        vector<char> children = el.second;
        if(children.size() > 1) { // should be always true? init?
            char representitive = children[0];
            for(int o = 1; o < children.size();o++) {
                ans.push_back(make_pair(representitive, children[o]));
            }
        }
    }
    cout << ans.size() << endl;
    for(int o = 0; o < ans.size();o++)
        cout << ans[o].first << ' ' << ans[o].second << endl;
}   


int main() {
    solution();
}
