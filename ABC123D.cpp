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
	return a * b / gcd(a, b);
}*/

int ABC123Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i, x) {
		cin >> a[i];
	}
	rep(i, y) {
		cin >> b[i];
	}
	rep(i, z) {
		cin >> c[i];
	}

	vector<ll> ab;

	rep(i, x) {
		rep(j, y) {
			ab.push_back(a[i] + b[j]);
		}
	}

	sort(allof(ab), greater<ll>());

	vector<ll> abc;

	rep(i, x * y) {
		if (i == k) break;
		rep(j, z) {
			if (j == k) break;
			abc.push_back(ab[i] + c[j]);
		}
	}

	sort(allof(abc), greater<ll>());

	rep(i, k) {
		cout << abc[i] << endl;
	}

	return 0;
}