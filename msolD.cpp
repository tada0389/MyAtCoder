#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/
/*
#define MAX_V 10010

vector<pair<ll, ll>> G[MAX_V];

// ダイクストラ法
vector<ll> dijkstra(ll start) {
	vector<ll> dist(MAX_V, infll);
	dist[start] = 0; // dist[i] := start->iまでの最短距離
	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
	que.push({ 0, start });
	while (!que.empty()) {
		ll cost, u; // 今までにかかった時間　現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if (dist[u] < cost) continue;
		for (auto tmp : G[u]) {
			ll v = tmp.first, time = tmp.second; // 隣接する頂点、その頂点まで行く時間
			if (dist[v] > dist[u] + time) {
				dist[v] = dist[u] + time;
				que.push({ dist[v], v });
			}
		}
	}
	return dist;
}

int n;
ll ans[MAX_V];
ll cnt = 0;
ll c[MAX_V];
bool used[MAX_V];

void dfs(int s) {
	if (used[s] == true) return;
	ans[s] = c[cnt++];
	used[s] = true;

	// 次にノード数の多い辺を先にやる
	sort(allof(G[s]), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
		return (int)G[a.first].size() > (int)G[b.first].size();
	});
	rep(i, (int)G[s].size()) {
		dfs(G[s][i].first);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<ll> a(n - 1), b(n - 1), tmpC(n);
	rep(i, n - 1) {
		cin >> a[i] >> b[i];
		G[a[i] - 1].push_back({ b[i] - 1, 0 });
		G[b[i] - 1].push_back({ a[i] - 1, 0 });
	}
	rep(i, n) cin >> tmpC[i];
	rep(i, n) used[i] = false;

	// 方針としては、辺が多い頂点に大きい値を与えたい
	// nは1e4なので比較的小さい もしかしたらO(n^2)もいける


	sort(allof(tmpC), greater<ll>());
	rep(i, n) {
		c[i] = tmpC[i];
	}
	
	vector<pair<ll, ll>> num(n);
	rep(i, n) num[i].second = i;

	// 隣の辺との差をできるだけ小さくした方がいいよね
	rep(i, n) {
		num[i].first = (int)G[i].size();
	}

	sort(allof(num), greater<pair<ll, ll>>());
	
	int maxIndex = 0;
	int maxNum = 0;
	rep(i, n) {
		if (maxNum < (int)G[i].size()) {
			maxNum = (int)G[i].size();
			maxIndex = i;
		}
	}

	dfs(maxIndex);

	ll res = 0;

	rep(i, n - 1) {
		// 辺を全通りみる
		ll mi;
		mi = min(ans[a[i] - 1], ans[b[i] - 1]);
		res += mi;
	}

	cout << res << endl;
	rep(i, n) cout << ans[i] << " ";
	cout << endl;


	return 0;
}
*/