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
#include <numeric>

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
	return a * b / gcd(a, b);
}*/

// 結構勉強になった気がする！

int Tenkamain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll mmod = 998244353;

	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll sum = 0;
	// ベクトルの要素をすべて足す関数 これからどんどん使ってきたい
	sum = accumulate(allof(a), 0);
	ll ans = 1;

	rep(i, n) {
		ans *= 3;
		ans %= mmod;
	}


	// dp[t][r]:=最初のt個の整数を塗り分け、赤い整数の和がrであるような場合の数
	vector<vector<ll>> dp(n + 1, vector<ll>(sum + 2, 0));
	dp[0][0] = 1;
	auto dp2 = dp;

	Rep(i, 0, n) {
		rep(j, sum + 2) {
			if (j - a[i] >= 0) {
				dp[i + 1][j] += dp[i][j - a[i]];
				dp[i + 1][j] %= mmod;
			}
			// 青か緑の2通り
			dp[i + 1][j] += dp[i][j] * 2;
			dp[i + 1][j] %= mmod;
		}
	}

	ll tmp = 0;
	ll halfSum = sum / 2;
	if (sum % 2) halfSum++;
	Rep(i, halfSum, sum + 2) {
		tmp += dp[n][i];
		tmp %= mmod;
	}
	tmp *= 3;
	tmp %= mmod;
	ans -= tmp;

	if (sum % 2 == 0) {
		// R = G = sum / 2、　R = B = sum / 2のときも考える
		rep(i, n) {
			rep(j, sum + 2) {
				if (j - a[i] >= 0) {
					dp2[i + 1][j] += dp2[i][j - a[i]];
					dp2[i + 1][j] %= mmod;
				}
				// 片方だけに入れる
				dp2[i + 1][j] += dp2[i][j];
				dp2[i + 1][j] %= mmod;
			}
		}
		// RG GB BRの3通り
		ans += dp2[n][halfSum] * 3;
	}

	if (ans < 0) {
		ans += mmod;
	}

	cout << ans % mmod << endl;

	return 0;
}