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
#include <iomanip>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右攜下昴 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 敘大公約摧
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 敘擣公倍摧
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/


int ABC131Fmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int>x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];

	// 長方形を探す

	ll ans = 0;
	// x軸とy軸 分けて考えれる
	// map
	vector<vector<int>> xy(100010, vector<int>());
	vector<vector<int>> yx(100010, vector<int>());
	rep(i, n) {
		xy[x[i]].push_back(y[i]);
		yx[y[i]].push_back(x[i]);
	}

	rep(i, 100010) {

	}

	return 0;
}
