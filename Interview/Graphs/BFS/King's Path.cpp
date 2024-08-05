/*%!@\$!@\$%&&\$#@%@^#%&\$**(\$%&%#\$%@#%^#@^&#@\$%#!@^@#^&@#^
░██████╗░█████╗░███╗░░░███╗██╗░░░██╗██████╗░░█████╗░██╗
██╔════╝██╔══██╗████╗░████║██║░░░██║██╔══██╗██╔══██╗██║
╚█████╗░███████║██╔████╔██║██║░░░██║██████╔╝███████║██║
░╚═══██╗██╔══██║██║╚██╔╝██║██║░░░██║██╔══██╗██╔══██║██║
██████╔╝██║░░██║██║░╚═╝░██║╚██████╔╝██║░░██║██║░░██║██║
╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝
^@#^@&@#%@*^%*&\$%^#\$^\$***%^#\$@%\$@#\$!@\$!@#\$%@#^@&@#%@#*/
#include <bits/stdc++.h>

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pls  {cout.tie(0);}
#define endl            "\n"
#define ll                      long long int
#define ull                     unsigned long long
#define pll                     pair<ll,ll> 
#define not_less_than(v, n) lower_bound(v.begin(), v.end(), n)                   // n >=
#define not_more_than(v, n) lower_bound(v.rbegin(), v.rend(), n, greater<ll>()) // n <=
#define more_than(v, n) upper_bound(v.begin(), v.end(), n)                       // n <
#define less_than(v, n) upper_bound(v.rbegin(), v.rend(), n, greater<ll>())     // n >
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define sps(pvec) sort(pvec.begin(),pvec.end(),[](const auto &a,const auto &b){return a.second<b.second;});
#define frq(mp) for(auto &element:mp)cout<<element.first<<" "<<element.second<<endl;
#define sw(x, y) \
    if (x < y)   \
        swap(x, y);
#define REP(o,l,r) for(long long o=(l);o<(r);o++)
#define PER(o,l,r) for(long long o=(r)-1;o>=(l);o--
#define debug(x)        cout<<'['<<#x<<" is "<<x<<"]"<<endl;
#define all(d)          d.begin(),d.end()
#define rall(d)         d.rbegin(), d.rend()
#define fe(d)   for(auto &oI : d) {cout << oI << " ";} cout << endl;

void print(ll x) { cout << x << endl;}

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct pos {
    ll x,y, level;
    pos(ll x, ll y, ll level) : x(x), y(y),level(level) {} 
};

map<pair<ll,ll>, bool> visited;
map<pair<ll,ll>, ll> dist;
set<pair<ll,ll>> st;

bool isValid(pair<ll,ll> pt) {
    return st.count(pt);
}

ll bfs(pair<ll,ll> src, pair<ll,ll> target) {
    queue<pair<ll,ll>> q;
    q.push(src);

    visited[src] = true;
    dist[src] = 0;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for(int o = 0; o < 8;o++) {
            ll row = x + dx[o];
            ll col = y + dy[o];
            pair<ll,ll> np = make_pair(row,col);
            if(!isValid(np) || visited[np])
                continue;

            q.push(np);
            visited[np] = true;
            dist[np] = dist[{x,y}] + 1;

            if(np.first == target.first && np.second == target.second) {
                return dist[np];
            }
        }
    }
    return -1;
}


void solution() {
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll k; cin >> k;
    while(k--) {
        ll r, u, v; cin >> r >> u >> v;
        for(int o = u; o <= v;o++) {
            st.insert(make_pair(r,o));
        }
    }
    
    return print(bfs(make_pair(x1,y1), make_pair(x2,y2)));
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * **Dont over think dude, simple things must remain simple >_>**
 * WRITE STUFF DOWN
 * *DON'T GET STUCK ON ONE APPROACH*
 * Always double check ma & mi in main
 * The sword is the axis of the world, and the samurai is the master of the sword.
 */


int32_t main() {
    send help pls
    solution();
    return 0;
}
