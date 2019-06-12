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
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int ABC127Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m);
	rep(i, m) cin >> l[i] >> r[i];

	// d•¡•”•ª‚ğæ‚é
	/*vector<ll> sum(n + 1, 0);

	rep(i, m) {
		sum[r[i]]++;
		sum[l[i] - 1]++;
	}

	rep(i, n + 1) {
		cout << sum[i] << " ";
	}
	cout << endl;*/

	int lmax = 0;
	int rmin = inf;
	rep(i, m) {
		lmax = max(lmax, l[i]);
		rmin = min(rmin, r[i]);
	}

	cout << max(rmin - lmax + 1, 0) << endl;
	return 0;
}
