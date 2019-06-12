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
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍŽÎ‚ß
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

int ternarySearchmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<double> x(n), y(n), c(n);
	rep(i, n) cin >> x[i] >> y[i] >> c[i];

	double left = -100001;
	double right = 100001;

	// ‰º‚É“Ê‚ÈƒOƒ‰ƒt
	// x‚ÉŠÖ‚µ‚Ä‚Ý‚é
	while (right - left > 1e-8) {
		double midL = (left * 2 + right) / 3;
		double midR = (left + right * 2) / 3;

		double disL = 0;
		double disR = 0;
		rep(i, n) {
			disL = max(disL, c[i] * fabs(x[i] - midL));
			disR = max(disR, c[i] * fabs(x[i] - midR));
		}
		if (disL >= disR) {
			left = midL;
		}
		else {
			right = midR;
		}
	}

	double ans = 0;
	rep(i, n) {
		ans = max(ans, c[i] * fabs(x[i] - left));
	}

	// y‚ÉŠÖ‚µ‚Ä‚Ý‚é
	double leftY = -100001;
	double rightY = 100001;
	while (rightY - leftY > 1e-8) {
		double midL = (leftY * 2 + rightY) / 3;
		double midR = (leftY + rightY * 2) / 3;

		double disL = 0;
		double disR = 0;
		rep(i, n) {
			disL = max(disL, c[i] * fabs(y[i] - midL));
			disR = max(disR, c[i] * fabs(y[i] - midR));
		}
		if (disL >= disR) {
			leftY = midL;
		}
		else {
			rightY = midR;
		}
	}
	double tmp = 0;
	rep(i, n) {
		tmp = max(tmp, c[i] * fabs(y[i] - leftY));
	}
	ans = max(ans, tmp);

	cout << ans << endl;

	return 0;
}
