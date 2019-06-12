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
// 0~3Ç‹Ç≈ÇÕâEç∂â∫è„ 4~7Ç‹Ç≈ÇÕéŒÇﬂ
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// ç≈ëÂåˆñÒêî
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// ç≈è¨åˆî{êî
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int ABC129Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	rep(i, m) cin >> a[i];

	vector<bool> can(n + 1, true);
	rep(i, m) {
		can[a[i]] = false;
	}

	// 1ï‡Ç©2ï‡êiÇﬂÇÈ
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	Rep(i, 1, n + 1) {
		if (!can[i]) continue;

		if (i == 1) {
			// àÍÇ¬ëOÇæÇØÇÇ›ÇÈ
			dp[i] += dp[i - 1];
		}
		else {
			if (can[i - 1]) dp[i] += dp[i - 1];
			if (can[i - 2]) dp[i] += dp[i - 2];
		}
		dp[i] %= mod;
	}

	cout << dp[n] % mod << endl;

	return 0;
}
