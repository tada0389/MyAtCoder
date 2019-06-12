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
#include <numeric>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍŽÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int ABC128Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	//vector<string>s(n);
	vector<int> p(n);
	vector<pair<string, int>>snum(n);
	rep(i, n) {
		cin >> snum[i].first >> p[i];
		snum[i].second = i + 1;
	}
	sort(allof(snum));
	vector<int> ans(n);

	string s = " ";
	int start = 0;
	int end = 0;
	rep(i, n) {
		if (s == snum[i].first) {
			end++;
		}
		if (s != snum[i].first) {
			if (start != end) {
				vector<pair<int, int>> tmp;
				for (int j = start; j <= end; j++) {
					tmp.push_back({ p[snum[j].second - 1], snum[j].second });
				}
				sort(allof(tmp), greater<pair<int, int>>());
				int cnt = 0;
				Rep(j, start, end + 1) {
					ans[j] = tmp[cnt++].second;
				}
			}
			ans[i] = snum[i].second;
			start = i;
			end = i;
			s = snum[i].first;
		}
	}

	if (start != end) {
		vector<pair<int, int>> tmp;
		for (int j = start; j <= end; j++) {
			tmp.push_back({ p[snum[j].second - 1], snum[j].second });
		}
		sort(allof(tmp), greater<pair<int, int>>());
		int cnt = 0;
		Rep(j, start, end + 1) {
			ans[j] = tmp[cnt++].second;
		}
	}

	rep(i, n) {
		cout << ans[i] << endl;
	}

	return 0;
}
