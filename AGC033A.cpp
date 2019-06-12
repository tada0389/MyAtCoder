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
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍÎ‚ß
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
}
*/

typedef pair<int, int> P;


int AGC033Amain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));

	queue<P> que;

	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				que.push({ i, j });
			}
		}
	}

	int ans = 0;

	while (1) {
		if (que.empty()) {
			cout << ans - 1 << endl;
			return 0;
		}

		vector<pair<int, int>> bpos;

		ans++;
		while (!que.empty()) {
			P p = que.front(); que.pop();
			// ˆÚ“®4•ûŒü‚ğƒ‹[ƒv
			for (int k = 0; k < 4; k++) {
				int nx = p.first + dx[k], ny = p.second + dy[k];

				if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
					if (a[nx][ny] == '.') {
						bpos.push_back({ nx, ny });
						a[nx][ny] = '#';
					}
				}
			}
		}

		rep(i, (int)bpos.size()) {
			que.push({ bpos[i].first, bpos[i].second });
		}
	}

	return 0;
}