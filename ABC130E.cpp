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
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍŽÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/


int AGC130Emain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> s(n), t(m);
	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];

	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
	dp[0][0] = 1;
	rep(i, n) {
		rep(j, m) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = 1;
				dp[i + 1][j + 1] %= mod;
			}
		}
	}

	/*rep(i, n + 1) {
		rep(j, m + 1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	ll ans = 0;

	rep(k, n + 1) {
		int i = k;
		int j = 0;
		int cnt = 0;
		while (i != n + 1 && j != m + 1) {
			if (dp[i++][j++] == 1) cnt++;
		}
		ll tmp;
		if (cnt == 0) tmp = 0;
		else {
			tmp = 1;
			rep(l, cnt - 1) tmp *= 2;
		}
		//cout << tmp << endl;
		ans += tmp;
		ans %= mod;
	}

	Rep(k,1, m + 1) {
		int i = 0;
		int j = k;
		int cnt = 0;
		while (i != n + 1 && j != m + 1) {
			if (dp[i++][j++] == 1) cnt++;
		}
		ll tmp;
		if (cnt == 0) tmp = 0;
		else {
			tmp = 1;
			rep(l, cnt - 1) tmp *= 2;
		}
		//cout << tmp << endl;
		ans += tmp;
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}
