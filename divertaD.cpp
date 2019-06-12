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
#include <list>

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
}
*/

int divertaDmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a);
	rep(i, a) cin >> s[i];
	vector<ll> t(b);
	rep(i, b) cin >> t[i];
	vector<ll> x(q);
	rep(i, q) cin >> x[i];

	// 2分探索？

	// ありえるパターン
	// →→、←←、→←、←→
	// 神社と寺の順番は任意

	// 二分探索でxの前後の点を神社と寺で探す
	// 距離を上の4パターン調べて最小値を出力

	rep(i, q) {
		ll ans = infll;

		int sback, sfront;
		int tback, tfront;

		sfront = lower_bound(allof(s), x[i]) - s.begin();
		sback = sfront - 1;
		tfront = lower_bound(allof(t), x[i]) - t.begin();
		tback = tfront - 1;

		//cout << i << "番目" <<  endl;
		// →→
		if (sfront < a && tfront < b){
			//cout << "→→" << max(s[sfront], t[tfront]) - x[i] << endl;
			ans = min(ans, max(s[sfront], t[tfront]) - x[i]);
		}
		// ←←
		if (sback >= 0 && tback >= 0) {
			//cout << "←←" << x[i] - min(s[sback], t[tback]) << endl;
			ans = min(ans, x[i] - min(s[sback], t[tback]));
		}
		// →←
		if (sfront < a && tback >= 0) {
			//cout << "→←" << s[sfront] - t[tback] << endl;
			ans = min(ans, s[sfront] - t[tback] + min(s[sfront] -x[i], x[i] - t[tback]));
		}
		// ←→
		if (sback >= 0 && tfront < b) {
			//cout << "←→" <<  t[tfront] - s[sback] << endl;
			ans = min(ans, t[tfront] - s[sback] + min(x[i] - s[sback], t[tfront] - x[i]));
		}
		cout << ans << endl;
	}

	return 0;
}
