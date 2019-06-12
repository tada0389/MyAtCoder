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
	return a * b / gcd(a, b);
}*/

int HCCmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int m;
	cin >> m;
	vector<char> d(m), f(m);
	rep(i, m) cin >> d[i] >> f[i];
	int q;
	cin >> q;
	vector<int> t(q), p(q);
	rep(i, q) cin >> t[i] >> p[i];

	// ‚Ü‚¸‚Í•”•ª“_
	vector<char> extendS(300);
	int head = 100;
	int tail = 100;
	rep(l, n) {
		extendS[tail++] = s[l];
	}
	head--;

	// n = 1‚ð–ž‚½‚·

	int tt = 0;
	vector<char> ans(q);
	rep(i, q) {
		ans[i] = t[i];
	}
	typedef map <ll, ll > M; // map<key ‚ÌŒ^, value‚ÌŒ^>
	M ma;
	rep(i, q) {
		ma[t[i]] = i;
	}

	vector<pair<int, int>> tp(q);
	rep(i, q) {
		tp[i].first = t[i];
		tp[i].second = p[i];
	}
	sort(allof(tp));

	rep(j, m) {
		if (d[j] == 'L') {
			extendS[head--] = f[j];
			int cnt = head + 2;
			Rep(k, head + 2, tail) {
				if (extendS[k] == f[j]) break;
				cnt = k;
			}
			if (cnt != tail - 1) {
				Rep(k, head + 2, cnt + 1) {
					extendS[k] = f[j];
				}
			}
		}
		else {
			extendS[tail++] = f[j];
			int cnt = tail - 2;
			for (int k = tail - 2; k > head; k--) {
				if (extendS[k] == f[j]) break;
				cnt = k;
			}
			if (cnt != head + 1) {
				for (int k = tail - 2; k >= cnt; k--) {
					extendS[k] = f[j];
				}
			}
		}

		if (tp[tt].first == (j + 1)) {
			//cout << tt << "”Ô–Ú‚Ì“Še" << endl;
			tp[tt].second = extendS[head + tp[tt].second];
			tt++;
		}
	}

	rep(i, q) {
		cout << tp[ma[tp[i].first]].second << endl;
	}

	return 0;
}