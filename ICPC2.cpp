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


int ICPC2main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;
	vector<string> field(h);
	rep(i, h) cin >> field[i];

	queue<pair<int, int>> que;
	vector<vector<bool>> isDead(h, vector<bool>(w, false));
	Rep(i,1, h - 1) {
		Rep(j, 1, w - 1) {
			if (field[i][j] == '.') continue;
			if (isDead[i][j]) continue;
			int cnt = 0;
			rep(k, 8) {
				if (field[i + dy[k]][j + dx[k]] == '.')
					cnt++;
			}
			if ((field[i][j] - '0') <= cnt) {
				que.push({ i, j });
				isDead[i][j] = true;
			}
		}
	}

	int ans = 0;

	if (que.empty()) {
		cout << 0 << endl;
		return 0;
	}

	while (!que.empty()) {
		queue<pair<int, int>> next;
		ans++;
		while (!que.empty()) {
			int x = que.front().second;
			int y = que.front().first;
			que.pop();
			field[y][x] = '.';

			rep(k, 8) {
				int cnt = 0;
				if (isDead[y + dy[k]][x + dx[k]]) continue;
				if (field[y + dy[k]][x + dx[k]] != '.') {
					rep(j, 8) {
						if (field[y + dy[k] + dy[j]][x + dx[k] + dx[j]] == '.') {
							cnt++;
						}
					}
					if ((field[y + dy[k]][x + dx[k]] - '0') <= cnt) {
						next.push({ y + dy[k], x + dx[k] });
						isDead[y + dy[k]][x + dx[k]] = true;
					}
				}
			}
		}
		que = next;
	}


	cout << ans << endl;

	return 0;
}
