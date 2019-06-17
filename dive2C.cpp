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
	return a / gcd(a, b) * b;
}*/


int dive2Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	// 最大値を求める
	ll m = -inf;
	vector<pair<int, int>> xy;

	// マイナスとプラスの組でやると、無駄がない
	// 始めにソート
	sort(allof(a));

	int posNum = 0;
	int negaNum = 0;
	int pi = 0;
	rep(i, n) {
		if (a[i] > 0) posNum++;
		else if (a[i] < 0) {
			negaNum++;
			pi = i;
		}
	}
	pi++;
	int zeroNum = n - posNum - negaNum;

	//cout << posNum << " " << negaNum << " " << zeroNum << endl;
	if (zeroNum == n) {
		cout << 0 << endl;
		rep(i, n - 1) {
			cout << 0 << " " << 0 << endl;
		}
		return 0;
	}

	if (n == 2) {
		cout << a[1] - a[0] << endl;
		cout << a[1] << " " << a[0] << endl;
		return 0;
	}

	// 正の数、負の数がそれぞれ一つでもあると、すべて簡単

		// 一番小さい負の数以外の負の数を一番大きい正の数に食わせる
		// 正の数も同様に
	int mi = a[0];
	int ma = a[n - 1];
	pi = min(pi, n - 1);
	Rep(i, 1, pi) {
		xy.push_back({ ma, a[i] });
		ma -= a[i];
	}
	Rep(i, pi, n - 1) {
		xy.push_back({ mi, a[i] });
		mi -= a[i];
	}
	// 最後に合成
	xy.push_back({ ma, mi });
	m = ma - mi;

	cout << m << endl;
	rep(i, n - 1) {
		cout << xy[i].first << " " << xy[i].second << endl;
	}
	//cout << xy.size() << endl;

	return 0;
}
