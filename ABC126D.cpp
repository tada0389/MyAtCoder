#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <list>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍŽÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/
/*
#define MAX_V 100010

// 
vector<pair<ll, ll>> G[MAX_V];
vector<int> color(MAX_V, 0);

void dfs(int from, int root) {
	rep(i, (int)G[from].size()) {
		int to = G[from][i].first;
		if (to == root) continue;
		if (G[from][i].second % 2 == 0) {
			color[to] = color[from];
		}
		else {
			color[to] = 1 - color[from];
		}
		dfs(to, from);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> u(n - 1), v(n - 1);
	vector<ll> w(n - 1);
	rep(i, n - 1) {
		cin >> u[i] >> v[i] >> w[i];
		G[u[i] - 1].push_back({ v[i] - 1,w[i] });
		G[v[i] - 1].push_back({ u[i] - 1, w[i] });
	}

	// ˆê‚ÂŒˆ‚ß‚Ä‚»‚ê‚©‚ç‚½‚Ç‚é
	color[0] = 0;
	dfs(0, -1);

	rep(i, n) {
		cout << color[i] << endl;
	}

	return 0;
}
*/