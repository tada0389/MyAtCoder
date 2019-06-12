#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
/*
#define INF 10e6
using namespace std;

// 状態を表すクラスpairの場合、typedefしておくと便利
typedef pair<int, int> P;

// 最短経路を求めてそれ以外の道を黒く塗りつぶせば良い

int h, w;
vector<vector<char>> field;
int gx, gy;
int sx, sy;

vector<vector<int>> d;

// 4方向の移動ベクトル
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<P> que;
	// スタート地点をキューに入れ、その点の距離を0とする
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	// キューが空になるまでループ
	while (que.size()) {
		// キューの先頭を取り出す
		P p = que.front(); que.pop();
		// 取り出した状態がゴールなら探索をやめる
		if (p.first == gx && p.second == gy) break;
		// 移動4方向をループ
		for (int i = 0; i < 4; i++) {
			// 移動した後の点を(nx, ny)とする
			int nx = p.first + dx[i], ny = p.second + dy[i];

			// 移動が可能かの判定と既に訪れたことがあるかの判定
			if (field[nx][ny] != '#' && d[nx][ny] == INF) {
				// 移動できるならキューに入れ、その点の距離をpからの距離+1で確定する
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}

int main() {
	cin >> h >> w;

	field = vector<vector<char>>(h+2, vector<char>(w+2,'#'));
	d = vector<vector<int>>(h + 2, vector<int>(w + 2,INF));

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> field[i][j];
		}
	}

	int cnt = 0;
	sx = 1;
	sy = 1;
	gx = h;
	gy = w;

	cnt = bfs();
	if (cnt == INF) cout << -1 << endl;
	else {
		int res = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (field[i][j] == '.')
					res++;
			}
		}
		res -= cnt + 1;
		cout << res << endl;
	}
}*/