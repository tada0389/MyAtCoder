#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
/*
#define INF 10e6
using namespace std;

// ��Ԃ�\���N���Xpair�̏ꍇ�Atypedef���Ă����ƕ֗�
typedef pair<int, int> P;

// �ŒZ�o�H�����߂Ă���ȊO�̓��������h��Ԃ��Ηǂ�

int h, w;
vector<vector<char>> field;
int gx, gy;
int sx, sy;

vector<vector<int>> d;

// 4�����̈ړ��x�N�g��
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int bfs() {
	queue<P> que;
	// �X�^�[�g�n�_���L���[�ɓ���A���̓_�̋�����0�Ƃ���
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	// �L���[����ɂȂ�܂Ń��[�v
	while (que.size()) {
		// �L���[�̐擪�����o��
		P p = que.front(); que.pop();
		// ���o������Ԃ��S�[���Ȃ�T������߂�
		if (p.first == gx && p.second == gy) break;
		// �ړ�4���������[�v
		for (int i = 0; i < 4; i++) {
			// �ړ�������̓_��(nx, ny)�Ƃ���
			int nx = p.first + dx[i], ny = p.second + dy[i];

			// �ړ����\���̔���Ɗ��ɖK�ꂽ���Ƃ����邩�̔���
			if (field[nx][ny] != '#' && d[nx][ny] == INF) {
				// �ړ��ł���Ȃ�L���[�ɓ���A���̓_�̋�����p����̋���+1�Ŋm�肷��
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