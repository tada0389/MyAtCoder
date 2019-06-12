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

int ABC127Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> b(m), c(m);
	vector<pair<ll, ll>> cb(m);
	rep(i, m) {
		cin >> b[i] >> c[i];
		cb[i].first = c[i];
		cb[i].second = b[i];
	}

	// çáåvíl
	// è¨Ç≥Ç¢Ç‚Ç¬Çè¡ÇµÇΩÇ¢
	sort(allof(a));
	sort(allof(cb), greater<pair<ll, ll>>());

	int index = 0;
	bool end = false;
	rep(i, m) {
		rep(j, cb[i].second) {
			if (a[index] < cb[i].first) {
				a[index++] = cb[i].first;
			}
			else {
				end = true;
				break;
			}
			if (index >= n) {
				end = true;
				break;
			}
		}
		if (end) break;
	}

	ll sum = 0;
	rep(i, n) {
		sum += a[i];
	}

	cout << sum << endl;

	return 0;
}
