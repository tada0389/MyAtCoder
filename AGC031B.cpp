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

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };
/*
void add(ll &a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
}

int AGC031Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<ll>w(n);
	rep(i, n) cin >> w[i];

	// dp[l][r]:= 区間[l, r)で取り除くことのできるブロックの数
	// [ <= ( <

	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

	Rep(i, 2, n + 1) {
		// left
		rep(l, n) {
			int r = l + i;
			if (r > n) continue;

			if (dp[l + 1][r - 1] == i - 2 && abs(w[l] - w[r - 1]) <= 1) {
				dp[l][r] = i;
			}

			Rep(mid, l, r + 1) {
				dp[l][r] = max(dp[l][r], dp[l][mid] + dp[mid][r]);
			}
		}
	}

	return 0;
}*/