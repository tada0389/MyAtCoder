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

int ABC129Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> w(n);
	rep(i, n) cin >> w[i];

	int ans = inf;
	// ëSíTçı
	rep(t, 101) {
		int s1 = 0;
		int s2 = 0;
		rep(j, n) {
			if (j <= t) s1 += w[j];
			else s2 += w[j];
		}
		//cout << s1 << " " << s2 << endl;
		ans = min(ans, abs(s1 - s2));
	}

	cout << ans << endl;

	return 0;
}
