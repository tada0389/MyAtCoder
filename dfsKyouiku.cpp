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
	return a * b / gcd(a, b);
}*/

/*
vector<vector<pair<int, int>>> al(100000);
vector<int> dist(100000, inf * -1);
vector<bool> used(100000, false);

bool bfs(int i, int d) {
	if (used[i]) {
		return d == dist[i];
	}

	used[i] = true;
	dist[i] = d;
	rep(j, al[i].size()) {
		if (!bfs(al[i][j].first, d + al[i][j].second)) return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	rep(i, m) {
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		al[l].push_back({ r, d });
		al[r].push_back({ l, -1 * d });
	}

	rep(i, n) {
		if (!used[i]) {
			if (!bfs(i, 0)) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}*/