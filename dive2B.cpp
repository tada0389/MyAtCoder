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

int dive2Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<ll, ll>> xy(n);
	rep(i, n) cin >> xy[i].first >> xy[i].second;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	sort(allof(xy), [](pair<ll, ll>x, pair<ll, ll>y) {
		return x.first < y.first;
	});

	map<pair<ll, ll>, ll> mp;

	rep(i, n) {
		mp[{xy[i].first, xy[i].second}] = 1;
	}

	ll ans = inf;

	vector<ll> pd(n * n + 1, 0), qd(n * n + 1, 0);
	int index = 0;
	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			pd[index] = xy[i].first - xy[j].first;
			qd[index] = xy[i].second - xy[j].second;
			index++;
		}
	}

	rep(j, index) {
		// èáÇ…å„ÇÎÇå©ÇƒÇ¢Ç≠
		ll tmp = 0;
		rep(i, n) {
			if (mp[{xy[i].first - pd[j], xy[i].second - qd[j]}] != 1) tmp++;
		}
		ans = min(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}
