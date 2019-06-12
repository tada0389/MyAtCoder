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
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	ll cnt = 0;

	// —¼•û‚Ì”‚ÌŒÂ”‚ð”‚¦‚Äˆø‚­

	ll zeroNum = 0;
	ll oneNum = 0;

	rep(i, s.size()) {
		if (s[i] == '0') {
			zeroNum++;
		}
		else {
			oneNum++;
		}
	}

	if (zeroNum >= oneNum) cnt = oneNum * 2;
	else cnt = zeroNum * 2;

	cout << cnt << endl;

	return 0;
}*/