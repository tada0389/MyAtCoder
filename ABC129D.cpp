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

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3Ç‹Ç≈ÇÕâEç∂â∫è„ 4~7Ç‹Ç≈ÇÕéŒÇﬂ
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// ç≈ëÂåˆñÒêî
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// ç≈è¨åˆî{êî
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int ABC129Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];

	// ó›êœòaÇ≈Ç¢Ç¢Ç∂Ç·ÇÒ
	vector<vector<int>> sumh(h + 1, vector<int>(w + 1, 0));
	vector<vector<int>> sumw(w + 1, vector<int>(h + 1, 0));

	rep(i, h) {
		Rep(j, 1, w + 1) {
			if (s[i][j-1] == '.') {
				sumh[i][j] = sumh[i][j - 1] + 1;
			}
			else {
				sumh[i][j] = 0;
			}
		}
	}

	rep(j, w) {
		Rep(i, 1, h + 1) {
			if (s[i-1][j] == '.') {
				sumw[j][i] = sumw[j][i - 1] + 1;
			}
			else {
				sumw[j][i] = 0;
			}
		}
	}
	//cout << "a" << endl;
	//ñﬂÇµÇƒÇ†Ç∞ÇÈ
	rep(i, h) {
		for (int j = w; j > 0; j--) {
			if (sumh[i][j] == 0) continue;
			if (sumh[i][j - 1] == 0)continue;
			sumh[i][j - 1] = sumh[i][j];
		}
	}

	rep(j, w) {
		for (int i = h; i > 0; i--) {
			if (sumw[j][i] == 0) continue;
			if (sumw[j][i - 1] == 0)continue;
			sumw[j][i - 1] = sumw[j][i];
		}
	}

	int ans = 0;

	//ëSíTçı
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == '#') continue;
			int tmp = 0;
			tmp = sumh[i][j + 1] + sumw[j][i + 1] - 1;
			ans = max(ans, tmp);
		}
	}

	cout << ans << endl;

	return 0;
}
