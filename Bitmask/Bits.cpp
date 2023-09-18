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
#include <queue>
#include <sstream>

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

/*
#define debug(obj) cout << #obj << ": " << to_string(obj) << endl;
#define debug1(obj, sz) cout << #obj << ": " << to_string(obj, sz) << endl;
#define debug2(obj, sz1, sz2) cout << "-----" << #obj << "-----\n"; for (int i=0; i<sz1; i++) cout << to_string(obj[i], sz2) << " "; cout << endl;
#define debug3(obj, sz1, sz2, sz3) cout << "-----" << #obj << "-----\n"; for (int i=0; i<sz1; i++) {for (int j=0; j<sz2; j++) cout << to_string(obj[i][j], sz3) << " "; cout << endl;} cout << endl;
saved for future depth check*/
//constexpr ll countbit(int x) {return __builtin_popcountll(x);} // # of bits set
//const int dx[4]{ 1, 0, -1, 0 }, dy[4]{ 0, 1, 0, -1 }; edges
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // adj

const ll mod = 998244353, inf = 1001001001, INF = 1e18, mx = 1e5 + 5; // NEVER EDIT!
const long double pi = 3.14159265359;
int mii(inf); ll mi(1e18), ma(-1), length_counter(0);

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // res rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b); // res rounded down
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
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

// Problem Link: https://codeforces.com/problemset/problem/484/A

ll PaliGO(ll l, ll r) {
	ll s = l;
	for (int o = 0; o <= 60; o++)
	{
		s = (l | (1ll << o));
		if (s > r)
			return l;
		l = s;
	}
	return s;
}

void solution() {
	ll l, r; cin >> l >> r;
	cout << PaliGO(l, r) << endl;
}



/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * **Dont over think dude, simple things must remain simple >_>**
 * WRITE STUFF DOWN
 * *DON'T GET STUCK ON ONE APPROACH*
 * Always double check ma & mi in main
 * A case won't handle itsself
 * The sword is the axis of the world, and the samurai is the master of the sword.
 */


int32_t main() {
	send help pls
		startTime = clock();
	//#ifndef ONLINE_JUDGE
		//freopen("input.txt", "r"1, stdin);
		//freopen("output.txt", "w", stdout);
	//#endif
	ll q; cin >> q;
	while (q--)
		solution();
	return 0;
}