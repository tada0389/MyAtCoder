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


int ABC130Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll w, h, x, y;
	cin >> w >> h >> x >> y;

	double ans = 0.0;

	// 2‚Â‚É•ªŠ„‚µ‚Ä¬‚³‚¢•û‚ÌÅ‘å’l

	// ‚Ç‚±‚«‚Ä‚à”¼•ª‚É•ªŠ„‚Å‚«‚é

	ans = double(w * h) / 2.0;

	bool ok = true;
	if (w % 2 == 1) ok = false;
	if (h % 2 == 1) ok = false;
	if (x != w / 2) ok = false;
	if (y != h / 2) ok = false;
	
	cout << fixed << setprecision(10) << ans;
	if (ok) cout << " " << 1 << endl;
	else cout << " " << 0 << endl;

	return 0;
}
