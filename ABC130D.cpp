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


int ABC130Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	// しゃくとり

	ll ans = 0;

	int left = 0;
	int right = 0;

	ll sum = 0;
	while (right <= n) {
		//cout << sum << endl;
		if (sum < k) {
			if(right < n)
				sum += a[right];
			right++;
			continue;
		}
		else {
			// 右にある分だけ足す
			ans += (n - right + 1);
			// leftを増やしてあげる
			sum -= a[left];
			left++;
			continue;
		}
		/*if (left == right) {
			sum += a[right];
			right++;
		}*/
	}

	cout << ans << endl;

	return 0;
}
