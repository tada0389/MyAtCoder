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

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1 << 60LL;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

// 型による変数のオーバーフローに気をつけろ！！
// 悩んだら図やグラフを書け！！悩む前から書け！！

int HCPC1Amain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<ll> c(n);
	rep(i, n - 1) cin >> c[i+1];
	// cはマイナスもある

	vector<ll> x(n, -1);

	// dp[i]:=i部屋までの最大値
	vector<ll>ap(n+1, 0);
	vector<ll>tp(n+1, 0); // 保存用 すべて通る
	ap[0] = 0;
	tp[0] = 0;
	for (int i = 1; i < n; i++) {
		tp[i] = tp[i - 1] + c[i];
		if (c[i] > 0) {
			ap[i] = ap[i-1] + c[i];
		}
		else {
			ap[i] = max(ap[i - 1] + c[i], 0LL);
		}
	}

	vector<ll>rap(n + 1, 0);
	vector<ll>rtp(n + 1, 0);
	rap[n] = 0;
	rtp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		rtp[i] = tp[i + 1] + c[i];
		if (c[i] > 0) {
			ap[i] = ap[i + 1] + c[i];
		}
		else {
			ap[i] = max(ap[i + 1] + c[i], 0LL);
		}
	}

	rep(i, n) {
		ll tMax = -1;
		// 左と右の2パターン
		/*if (i == 0) {
			x[i] = ap[n-1];
		}
		else if (i == n) {
			x[i] = tap[0];
		}
		{*/
			// 右
			tMax = max(tMax, ap[i]);
			// 左
			tMax = max(tMax, rap[i]);

			x[i] = tMax;
		//}
	}

	rep(i, n) {
		cout << x[i] << endl;
	}

	return 0;
}