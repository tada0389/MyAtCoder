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


int binary_searchmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];

	// 一体にAダメージ、他にBダメージ

	sort(allof(h), greater<ll>());

	// 最もHPが高いやつに集中する

	// 全員にダメージBを追わせ
	// ある一人に対する追加ダメージをA - B与える

	// 貪欲法
	ll ans = 0;
	ll damage = 0;

	// T回の攻撃で全ての魔物を倒せるか？
	// 倒せる最小のTを探す
	// T(i)が満たしているならT(i+1)も満たす　
	// 2分探索

	int left = 0;
	int right = h[0] / b;
	if (h[0] % b != 0) right++;
	int mid = (right + left) / 2;

	while (left < right) {
		//cout << "l, m, r = " << left << " " << mid << " " << right << endl;
		ll cnt = 0;
		rep(i, n) {
			if (h[i] > mid * b) {
				cnt += (ll)(h[i] - mid * b) / (a - b);
				if ((h[i] - mid * b) % (a - b) != 0) cnt++;
			}
		}
		//cout << cnt << endl;
		if (cnt > (ll)mid) {
			// もっと攻撃回数を増やす
			left = mid + 1;
			mid = (right + left) / 2;
		}
		else if (cnt < (ll)mid) {
			// 攻撃回数を減らす
			right = mid - 1;
			mid = (right + left) / 2;
		}
		else { // ぴったし
			break;
		}
	}

	ll cnt = 0;
	rep(i, n) {
		if (h[i] > mid * b) {
			cnt += (ll)(h[i] - mid * b) / (a - b);
			if ((h[i] - mid * b) % (a - b) != 0) cnt++;
		}
	}
	if (cnt > (ll)mid) mid++;

	cout << mid << endl;

	return 0;
}
