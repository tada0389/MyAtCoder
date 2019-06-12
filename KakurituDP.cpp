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

int KakurituDPmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<double> p(n);
	rep(i, n) cin >> p[i];

	// ナップザック系？
	vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
	// dp[i][j] = i番目まで見たときに表がj個である確率

	dp[0][0] = 1.0;

	rep(i, n) {
		rep(j, n) {
			// 表の時
			dp[i + 1][j + 1] += dp[i][j] * p[i];
			// 裏の時
			dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
		}
	}

	double ans = 0;
	int border = (n + 1) / 2;
	Rep(j, border, n + 1) {
		ans += dp[n][j];
	}

	//ans /= (double)n;
	cout << fixed << setprecision(10) << ans << endl;

	return 0;
}
