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

int Vectrmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;
	vector<int> p(m), y(m);
	vector<vector<int>> py(n + 1, vector<int>());

	rep(i, m) {
		cin >> p[i] >> y[i];
		py[p[i]].push_back(y[i]); // 目新しい形！
	}

	rep(i, n) sort(allof(py[i + 1]));
	rep(i, m) {
		printf("%06d%06d\n", p[i], lower_bound(allof(py[p[i]]), y[i]) -
			py[p[i]].begin() + 1);
	}

	return 0;
}