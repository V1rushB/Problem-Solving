/*%!@$!@$%&&$#@%@^#%&$**($%&%#$%@#%^#@^&#@$%#!@^@#^&@#^
░██████╗░█████╗░███╗░░░███╗██╗░░░██╗██████╗░░█████╗░██╗
██╔════╝██╔══██╗████╗░████║██║░░░██║██╔══██╗██╔══██╗██║
╚█████╗░███████║██╔████╔██║██║░░░██║██████╔╝███████║██║
░╚═══██╗██╔══██║██║╚██╔╝██║██║░░░██║██╔══██╗██╔══██║██║
██████╔╝██║░░██║██║░╚═╝░██║╚██████╔╝██║░░██║██║░░██║██║
╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝
^@#^@&@#%@*^%*&$%^#$^$***%^#$@%$@#$!@$!@#$%@#^@&@#%@#*/
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <bitset>
#include <limits>

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pls  {cout.tie(0);}
#define endl		"\n"
#define ll			long long int
#define ull			unsigned long long	
#define mk			make_pair
#define pll			pair<ll,ll> 
#define not_less_than(v, n) lower_bound(v.begin(), v.end(), n)                   // n >=
#define not_more_than(v, n) lower_bound(v.rbegin(), v.rend(), n, greater<ll>()) // n <=
#define more_than(v, n) upper_bound(v.begin(), v.end(), n)                       // n <
#define less_than(v, n) upper_bound(v.rbegin(), v.rend(), n, greater<ll>())     // n >
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define sps(pvec) sort(pvec.begin(),pvec.end(),[](const auto &a,const auto &b){return a.second<b.second;});
#define frq(mp) for(auto &element:mp)cout<<element.first<<" "<<element.second<<endl;
#define REP(o,l,r) for(long long o=(l);o<(r);o++)
#define PER(o,l,r) for(long long o=(r)-1;o>=(l);o--
#define debug(x)	cout<<'['<<#x<<" is "<<x<<"]"<<endl;
#define cin(v) for(auto& it : v) cin >> it
#define all(d)		d.begin(),d.end()
#define rall(d)		d.rbegin(), d.rend()
#define fe(d)	for(auto &oI : d) {cout << oI << " ";} cout << endl;
#define pb(b)	push_back(b);
//constexpr ll countbit(int x) {return __builtin_popcountll(x);} // # of bits set
//const int dx[4]{ 1, 0, -1, 0 }, dy[4]{ 0, 1, 0, -1 }; edges
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // adj

const ll mod = 998244353, inf = 1e9, INF = 1e18, mx = 1e5;
const long double pi = 3.14159265359;
int mii(inf); ll mi(1e18), ma(-1), length_counter(0);

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // res rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b); // res rounded down
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

clock_t startTime;
double getTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

vector<ll> sieve(mx);
vector<ll> checkprime(mx);
void sievee() {
	for (int o = 2; o < mx; o++) {
		if (!checkprime[o]) {
			checkprime[o] = true; sieve[o] = o;
			for (int i = o + o; i < mx; i += o) { checkprime[i] = true; sieve[i] = o; }
		}
	}
}
void yes(bool t = 1) { cout << (t ? "YES\n" : "NO\n"); }
void no(bool t = 1) { yes(!t); }
void print(ll x) { cout << x << endl; }
char alpha[] = { 'a','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

//readable version of the code
//None

vector<vector<ll>> dp;
vector<ll> d1, d2;

ll dpcal(ll o, int x) {

	if (o == dp.size())
		return 0;
	if (~dp[o][x])
		return dp[o][x];

	if (x == 0)
		dp[o][x] = max({ dpcal(o + 1,0),dpcal(o + 1,1) + d1[o],dpcal(o + 1,2) + d2[o] });
	else if (x == 1)
		dp[o][x] = max(dpcal(o + 1, 0), dpcal(o + 1, 2) + d2[o]);
	else {
		dp[o][x] = max(dpcal(o + 1, 0), dpcal(o + 1, 1) + d1[o]);
	}
	return dp[o][x];

}

void solution() {
	ll a; cin >> a;
	d1.resize(a);
	d2.resize(a);
	dp.resize(a, vector<ll>(3, -1));
	for (ll& el : d1)
		cin >> el;
	for (ll& el : d2)
		cin >> el;
	return print(dpcal(0, 0));

}



/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * **Dont over think dude, simple things must remain simple >_>**
 * WRITE STUFF DOWN
 * *DON'T GET STUCK ON ONE APPROACH*
 * Always double check ma & mi in main
 *
 * The sword is the axis of the world, and the samurai is the master of the sword.
 */


int32_t main() {
	send help pls
		startTime = clock();
	//#ifndef ONLINE_JUDGE
		//freopen("input.txt", "r"1, stdin);
		//freopen("output.txt", "w", stdout);
	//#endif
	//ll q; cin >> q;
	//while (q--)
	solution();
	return 0;
}