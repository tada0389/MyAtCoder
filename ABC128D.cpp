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
	return a / gcd(a, b) * b;
}*/

int ABC128Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	rep(i, n) cin >> v[i];

	// マイナスの場合もあるのか

	// 左右それぞれ取る場所の線を二本入れる

	ll ans = -inf;

	vector<ll> lv;
	for (int left = -1; left < n; left++) {
		if (left >= 0) lv.push_back(v[left]);
		vector<ll> rv;
		for (int right = n; right > left; right--) {
			if (right < n) rv.push_back(v[right]);
			ll rest = k - (n - right + left + 1);
			if (rest < 0)continue;
			rest = min(rest, left + 1 + n - right);
			if ((int)lv.size() + (int)rv.size() == 0) {
				ans = max(ans, 0LL);
				continue;
			}
			// rest個戻せる
			sort(allof(lv));
			sort(allof(rv));
			int lcnt = 0;
			int rcnt = 0;
			rep(i, rest) {
				ll l, r;
				if (lcnt >= (int)lv.size())
					l = inf;
				else
					l = lv[lcnt];
				if (rcnt >= (int)rv.size())
					r = inf;
				else
					r = rv[rcnt];

				if (l < 0 || r < 0) {
					if (l < r) {
						lcnt++;
					}
					else {
						rcnt++;
					}
				}
			}
			ll tmp = 0;
			Rep(i, lcnt, (int)lv.size()) {
				tmp += lv[i];
			}
			Rep(i, rcnt, (int)rv.size()) {
				tmp += rv[i];
			}
			ans = max(ans, tmp);
		}
	}

	cout << ans << endl;

	return 0;
}
