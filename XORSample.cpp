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
	return a / gcd(a, b) * b;
}*/

int xormain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int m, k;
	cin >> m >> k;

	// xor は a^bでできる

	// 同じ数が必ず2つ
	// その距離の間のすべてのXORはkとなる(自身も含む)

	// kとのXORが0となればよい

	// 自分自身も含むので、始点と終点のXORは0

	// 2^mのすべてが正しくなければならない

	// kの値と等しいaの他のaを任意に使ってkを作れればよい

	if (m == 0) {
		if (k == 0) {
			cout << 0 << " " << 0 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}

	if (m == 1) {
		if (k == 0) {
			cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}

	if ((1 << m) <= k) {
		cout << -1 << endl;
		return 0;
	}

	if (k == 0) {
		rep(bit, 1 << m) {
			cout << bit << " " << bit << " ";
		}
		cout << endl;
		return 0;
	}

	vector<pair<int, int>> ans;
	// 全部入れてしまう
	rep(bit, 1 << m) {
		ans.push_back({ min(bit, bit ^ k), max(bit, bit ^ k) });
	}

	sort(allof(ans));
	// これにより、重複成分を削除して、削除されて余った長さ分を調整する
	ans.erase(unique(allof(ans)), ans.end());
	// 全ペアを2つ2組で作って並べる
	// ex) (0 5) (1 4) (5 0) (4 1)

	for (int i = 0; i < ans.size(); i += 2) {
		cout << ans[i].first << " " << ans[i].second << " ";
		cout << ans[i + 1].first << " " << ans[i + 1].second << " ";
		cout << ans[i].second << " " << ans[i].first << " ";
		cout << ans[i + 1].second << " " << ans[i + 1].first << " ";
	}
	cout << endl;

	return 0;
}
