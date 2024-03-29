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


int ABC131Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, l;
	cin >> n >> l;

	vector<int> taste(n, 0);

	// なるべく0に近いものを食べる
	rep(i, n) {
		taste[i] = l + i;
	}

	sort(allof(taste), [&](int x, int y) {
		return abs(x) < abs(y);
	});

	int sum = 0;
	Rep(i,1, n) {
		sum += taste[i];
	}

	cout << sum << endl;

	return 0;
}
