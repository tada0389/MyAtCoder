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
#include <cstring>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

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
	return gcd(b, a%b);
}

// Å¬Œö–ñ”
long lcm(long a, long b) {
	return a / gcd(a, b) * b;
}*/

int ABC120Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll a, b, k;
	cin >> a >> b >> k;

	ll cnt = 0;
	for (int i = a; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			cnt++;
			if (cnt == k) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}