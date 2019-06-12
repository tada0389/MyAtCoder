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

int ABC128Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> k(m);
	vector<vector<int>> s(m, vector<int>());
	rep(i, m) {
		cin >> k[i];
		rep(j, k[i]) {
			int tmp;
			cin >> tmp;
			s[i].push_back(tmp);
		}
	}
	vector<int> p(m);
	rep(i, m) cin >> p[i];

	// n個のスイッチでオンオフの2^10通り試す

	ll ans = 0;

	rep(bit, 1 << n) {
		bool ok = true;
		rep(i, m) {
			int cnt = 0;
			rep(j, k[i]) {
				if (bit & (1 << (s[i][j] - 1))) {
					cnt++;
				}
			}
			if (cnt % 2 != p[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
