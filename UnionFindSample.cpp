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

// Union-Find �� (Verified: AtCoder Typical Contest 001 B)
/*
struct UnionFind {
private:
	const int n;
	int __size;
	vector<int> uf;
public:
	// ������ UnionFind uni(n) �̂悤�ɐ錾����Ηǂ�
	UnionFind(int _n) : n(_n), __size(_n), uf(_n, -1) {}
	// find (�؂̍������߂�)
	int find(int x) { return (uf[x] < 0) ? x : uf[x] = find(uf[x]); }
	// x �� y �������W���ɑ����邩�ǂ���
	bool same(int x, int y) { return find(x) == find(y); }
	// x ��������W���̗v�f��
	int size(int x) { return -uf[find(x)]; }
	// �W���͂������邩
	int size() { return __size; }
	// x �� y �̑�����W���𕹍�
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		__size--;
		if (uf[y] < uf[x]) swap(x, y);
		uf[x] += uf[y]; uf[y] = x;
		return true;
	}
};

using Graph = vector< vector<int> >;


int unionmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ab(m);
	rep(i, m) cin >> ab[i].first >> ab[i].second;

	int ans = 0;

	rep(i, m) {
		// �؂����
		UnionFind uni(n);

		rep(j, m) {
			// �����ȊO�̕ӂ��Ȃ��ŘA��������2�ƂȂ����狴
			if (i == j) continue;
			uni.unite(ab[j].first - 1, ab[j].second - 1);
		}
		if (uni.size() != 1) ans++;
	}

	cout << ans << endl;

	return 0;
}*/