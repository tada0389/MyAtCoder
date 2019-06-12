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
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}*/

/*
#define MAX_V 100010
#define MAX_E 200010

struct UnionFind {
private:
	const int n;
	int __size;
	vector<int> uf;
public:
	// 初期化 UnionFind uni(n) のように宣言すれば良い
	UnionFind(int _n) : n(_n), __size(_n), uf(_n, -1) {}
	// find (木の根を求める)
	int find(int x) { return (uf[x] < 0) ? x : uf[x] = find(uf[x]); }
	// x と y が同じ集合に属するかどうか
	bool same(int x, int y) { return find(x) == find(y); }
	// x が属する集合の要素数
	int size(int x) { return -uf[find(x)]; }
	// 集合はいくつあるか
	int size() { return __size; }
	// x と y の属する集合を併合
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

struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E; // 頂点数と辺数

int kruskal() {
	sort(es, es + E, comp); // edge.costが小さい順にソートする

	UnionFind uni(V);
	int res = 0;
	rep(i, E) {
		edge e = es[i];
		if (!uni.same(e.u, e.v)) {
			uni.unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> xy(n);
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		xy[i].first.first = x;
		xy[i].first.second = y;
		xy[i].second = i;
	}

	auto yx = xy;
	rep(i, n) {
		int x = xy[i].first.first;
		int y = xy[i].first.second;
		yx[i].first.first = y;
		yx[i].first.second = x;
	}

	sort(allof(xy));
	sort(allof(yx));

	E = n * 2 - 2;
	V = n;


	
	rep(i, n) {
		cout << xy[i].second << "番目 " << xy[i].first.first << ", " << xy[i].first.second << endl;
	}
	rep(i, n) {
		cout << xy[i].second << "番目 " << yx[i].first.first << ", " << yx[i].first.second << endl;
	} // できてた 

	rep(i, n - 1) {
		es[i].u = xy[i].second;
		es[i].v = xy[i + 1].second;
		es[i].cost = min(abs(xy[i].first.first - xy[i + 1].first.first), abs(xy[i].first.second - xy[i + 1].first.second));
	}

	rep(i, n - 1) {
		es[i + n - 1].u = yx[i].second;
		es[i + n - 1].v = yx[i + 1].second;
		es[i + n - 1].cost = min(abs(yx[i].first.first - yx[i + 1].first.first), abs(yx[i].first.second - yx[i + 1].first.second));
	}

	int ans = kruskal();

	cout << ans << endl;

	return 0;
}*/