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
	return a * b / gcd(a, b);
}*/


int ABC125Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll ans = 0;

	// —×‚è‡‚¤“ñ‚Â‚Ì³•‰‚ğ”½“]‚·‚é
	ll minusNum = 0;
	rep(i, n) {
		if (a[i] < 0) minusNum++;
		a[i] = abs(a[i]);
	}

	sort(allof(a));
	minusNum %= 2;

	rep(i, n) {
		if (i < minusNum) ans -= a[i];
		else ans += a[i];
	}

	cout << ans << endl;

	return 0;
}