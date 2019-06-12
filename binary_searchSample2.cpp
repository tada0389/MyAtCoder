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
	return a / gcd(a, b) * b;
}*/
/*
int simulate(const string &s, const vector<char> &t, const vector<char> &d, int pos) {
	rep(i, (int)t.size()) {
		if (s[pos] != t[i]) continue;
		if (d[i] == 'L') pos--;
		else pos++;
		if (pos < 0) return 1;
		if (pos >= (int)s.size()) return -1;
	}
	return 0;
}

int binarymain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<char>t(q), d(q);
	rep(i, q) cin >> t[i] >> d[i];

	int left = -1;
	int right = n;

	// ���̋��E����T��
	while (right - left > 1) {
		int midL = (right + left) / 2;
		int ok = simulate(s, t, d, midL);
		if (ok == 1) {
			// �E��T��
			left = midL;
		}
		else right = midL;
	}
	// mid = low, right = low + 1 = mid + 1 �ƂȂ��Ă���
	int left_fall = right; // right�̃C���f�b�N�X�̃S�[�����͗����Ȃ�

	// �E�̋��E����T��
	left = -1;
	right = n;
	while (right - left > 1) {
		int midR = (right + left) / 2;
		int ok = simulate(s, t, d, midR);
		if (ok == -1) right = midR;
		else left = midR;
	}
	int right_fall = n - 1 - left; // left�̃C���f�b�N�X�̃S�[�����͗����Ȃ�

	cout << n - (left_fall + right_fall) << endl;

	return 0;
}
*/