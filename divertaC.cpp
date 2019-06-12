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
	return a * b / gcd(a, b);
}
*/

int divertaCmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	// 最後がAで終わる　かつ　最初がBで始まるなら +1

	int aCnt = 0;
	int bCnt = 0;
	int baCnt = 0;
	int ans = 0;

	rep(i, n) {
		if (s[i][0] == 'B' && s[i][(int)s[i].size() - 1] == 'A') {
			baCnt++;
		}
		
		if (s[i][0] == 'B') bCnt++;
		if (s[i][(int)s[i].size() - 1] == 'A') aCnt++;
		
		Rep(j,1, (int)s[i].size()) {
			if (s[i][j - 1] == 'A' && s[i][j] == 'B') {
				ans++;
			}
		}
	}

	ans += min(aCnt, bCnt);

	if (aCnt == bCnt && bCnt == baCnt && aCnt != 0) ans--;

	// BA BA のときは1つしかできない
	cout << ans << endl;

	return 0;
}
