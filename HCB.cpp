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

int AAAmain() {
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

	// �܂��͕����_
	rep(i, q) {

		vector<char> extendS(300);
		int head = 100;
		int tail = 100;
		rep(i, n) {
			extendS[tail++] = s[i];
		}
		head--;

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

			//Rep(k, head + 1, tail) {
			//	cout << extendS[k] << " ";
			//}
			if (t[i] == (j + 1)) {
				cout << extendS[head + p[i]] << endl;
			}
		}
	}

	return 0;
}