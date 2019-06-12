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

// �x���}���t�H�[�h�@���g�������ł�
/*
#define MAX_V 1010
#define MAX_E 2019

// ���_from���璸�_to�ւ̃R�X�gcost�̕�
struct edge { ll from, to, cost; };

edge es[MAX_E];

ll d[MAX_V]; // �ŒZ����
int V, E;

// s�Ԗڂ̒��_����e���_�ւ̍ŒZ���������߂�
void shortest_path(int s) {
	rep(i, V) d[i] = infll;
	d[s] = 0;
	while (true) {
		bool update = false;
		rep(i, E) {
			edge e = es[i];
			if (d[e.from] != infll && d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update) break;
	}
}

// true�Ȃ畉�̕H�����݂���
bool find_negative_loop() {
	memset(d, 0, sizeof(d));
	rep(i, V) {
		rep(j, E) {
			edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost) {
				d[e.to] = d[e.from] + e.cost;

				// n��ڂɂ��X�V������Ȃ畉�̕H�����݂���
				if (i == V - 1) return true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<ll> a(m), b(m), c(m);
	V = n;
	E = m;
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		c[i] *= -1;
		es[i].from = a[i] - 1;
		es[i].to = b[i] - 1;
		es[i].cost = c[i];
	}

	if (find_negative_loop()) {
		cout << "inf" << endl;
		return 0;
	}

	shortest_path(0);

	ll ans = d[n - 1];

	cout << -ans << endl;

	return 0;
}*/