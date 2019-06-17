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

int dive2Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<ll, ll>> xy(n);
	rep(i, n) cin >> xy[i].first >> xy[i].second;

	sort(allof(xy), [](pair<ll, ll>x, pair<ll, ll>y) {
		return x.first < y.first;
	});
	//sort(allof(xy));

	map<pair<ll, ll>, ll> mp;

	rep(i, n) {
		//cout << xy[i].first << " " << xy[i].second << endl;
		mp[{xy[i].first, xy[i].second}] = 1;
	}

	// p, qをそれぞれ適当にきめる
	// n = 50
	// 50 * 50 全探索

	ll ans = inf;

	//cout << mp[{1, 1}] << " " << mp[{2, 2}] << endl;
	// マイナスにする意味はない
	Rep(p, 0, n ) {
		Rep(q, 0, n) {
			if (p == 0 && q == 0) continue;
			// 順に後ろを見ていく
			ll tmp = 0;
			rep(i, n) {
				if (mp[{xy[i].first - p, xy[i].second - q}] != 1) tmp++;
			}
			ans = min(ans, tmp);
		}
	}

	cout << ans << endl;

	return 0;
}
