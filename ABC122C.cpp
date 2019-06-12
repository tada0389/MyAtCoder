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
	return a * b / gcd(a, b);
}*/


int ABC122Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> l(q), r(q);
	rep(i, q) {
		cin >> l[i] >> r[i];
	}

	// ó›êœòa
	vector<int> sum(n, 0);
	sum[0] = 0;
	Rep(i, 1, n) {
		if (s[i] == 'C' && s[i - 1] == 'A') {
			sum[i] = sum[i - 1] + 1;
		}
		else {
			sum[i] = sum[i - 1];
		}
	}


	rep(i, q) {
		int ans = 0;
		if (l[i] - 2 < 0) {
			ans = sum[r[i] - 1];
		}
		else {
			ans = sum[r[i] - 1] - sum[l[i] - 1];
		}
		cout << ans << endl;
	}

	return 0;
}