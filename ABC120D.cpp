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
#include <cstring>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

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
	return gcd(b, a%b);
}

// 最小公約数
long lcm(long a, long b) {
	return a / gcd(a, b) * b;
}*/
/*

ll par[100000 + 10];
ll ran[100000 + 10];

// n要素で初期化
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		ran[i] = 0;
	}
}

// 木の根を求める
int find(ll x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

// xとyの属する集合を併合
void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (ran[x] < ran[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (ran[x] == ran[y]) ran[x]++;
	}
}

// xとyが同じ集合に属するか否か
bool same(ll x, ll y) {
	return find(x) == find(y);
}



int ABC120Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<ll> a(m+1), b(m+1);

	for (int i = m; i > 0; i--)
		cin >> a[i] >> b[i];

	vector<ll> ans(m + 1);

	ans[0] = (n * (n - 1)) / 2;

	vector<ll> land(n, 1);


	// 計算量はO(n)かO(nlogn)

	// 端がない状態から考える

	// union-find木作成
	init(n);

	ll group = n;

	Rep(i, 1, m + 1) {
		if (same(a[i], b[i])) {
			// もとから属していたらスルー
			ans[i] = ans[i - 1];
			unite(a[i], b[i]); // 木を併合 一応
		}
		else {
			group--;
			if (group == 1) {
				unite(a[i], b[i]); // 木を併合
				ans[i] = 0;
				break;
			}
			ans[i] = ans[i - 1] - land[find(a[i])] * land[find(b[i])]; // aに属している数*bに属している数を引く
			land[find(a[i])] += land[find(b[i])];
			land[find(b[i])] = land[find(a[i])];
			unite(a[i], b[i]); // 木を併合
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}

	return 0;
}*/