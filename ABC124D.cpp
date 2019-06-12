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
}*/


int ABC124Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int ans = 0;

	// 愚直でいんじゃね？
	// しゃくとり法で行ける

	ll cnt = 0;

	int right = 0;

	for (int left = 0; left < n; left++) {

		while (right < n && (cnt < k || s[right] == '1')) {
			if (right == 0 && right != n - 1) {
				if (s[right] == '0' && s[right + 1] == '1') {
					cnt++;
					right++;
				}
				else {
					right++;
				}
			}
			else if (right == n - 1) {
				if (s[right] == '0') {
					cnt++;
					right++;
				}
				else {
					right++;
				}
			}
			else if (s[right] == '0' && s[right + 1] == '1') {
				cnt++;
				right++;
			}
			else {
				right++;
			}
		}

		ans = max(ans, right - left);
		if (right == left) right++;
		else if (left != n - 1) {
			if (s[left] == '0' && s[left + 1] == '1') {
				cnt--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}