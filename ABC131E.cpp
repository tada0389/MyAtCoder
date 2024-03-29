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
// 0~3までは右攜下昴 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 敘大公約摧
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 敘擣公倍摧
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/


int ABC131Emain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	// ちょうどK個つくってあげる

	// 木構造
	// いらない分は一本に伸ばしてあげる

	//まずできるか
	ll sum = 0;
	rep(i, n - 1) sum += i;
	if (sum < k) {
		cout << -1 << endl;
		return 0;
	}

	// 一本線でも最短距離2は存在する l - 2個

	// ここ変えなきゃ
	if (true) {
		// 閉路を作らなきゃいけない

		// すべてが中心からつながっている
		vector<pair<int, int>> ans;
		Rep(i, 1, n) {
			ans.push_back({ i + 1, 1 });
		}
		// さらに閉路を作ってあげる
		int tmp = sum;
		// 一個一個つなげる
		int i = 2;
		int j = 3;
		int m = n - 1;
		while (tmp != k) {
			ans.push_back({ i, j });
			j++;
			if (j > n) {
				i++;
				j = i + 1;
			}
			tmp--;
			m++;
		}

		cout << m << endl;
		rep(l, m) {
			cout << ans[l].first << " " << ans[l].second << endl;
		}

		return 0;
	}

	int index = -1;
	// k個存在する
	// 何頂点で作るか全探索
	Rep(i, 3, n + 1) {
		ll first = 0;
		rep(j, i - 1) {
			first += j;
		}
		ll second = 0;
		second = n - (i - 2) - 2;

		//cout << first + second << endl;
		if (first + second == k) {
			index = i;
			break;
		}
	}

	if (index == -1) { // ここは関係なかった 絶対できる
		cout << -1 << endl;
		return 0;
	}

	// グラフを作ってあげる
	ll m = n - 1;
	vector<pair<int, int>> ans;
	// まずindexの個数
	// 中央を1にする
	Rep(i, 1, index) {
		ans.push_back({ i + 1, 1 });
	}

	// 次に一番大きい点から伸ばしてあげる
	Rep(i, index, n) {
		ans.push_back({ i, i + 1 });
	}

	cout << m << endl;
	rep(i, m) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}
