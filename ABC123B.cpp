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
// 0~3�܂ł͉E������ 4~7�܂ł͎΂�
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// �ő����
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// �ŏ����{��
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}*/

int ABC123Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<int> a(5);
	rep(i, 5) cin >> a[i];

	int time = 0;

	int mi = 10;

	rep(i, 5) {
		if (a[i] % 10 == 0) {
			time += a[i];
		}
		else {
			time += a[i] + 10 - (a[i] % 10);
			mi = min(mi, a[i] % 10);
		}
	}

	time -= 10 - mi;

	cout << time << endl;

	return 0;
}