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
#include <cstring>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

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
	return gcd(b, a%b);
}

// �ŏ�����
long lcm(long a, long b) {
	return a / gcd(a, b) * b;
}*/
/*

ll par[100000 + 10];
ll ran[100000 + 10];

// n�v�f�ŏ�����
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		ran[i] = 0;
	}
}

// �؂̍������߂�
int find(ll x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

// x��y�̑�����W���𕹍�
void unite(ll x, ll y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (ran[x] < ran[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (ran[x] == ran[y]) ran[x]++;
	}
}

// x��y�������W���ɑ����邩�ۂ�
bool same(ll x, ll y) {
	return find(x) == find(y);
}



int ABC120Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	vector<ll> a(m+1), b(m+1);

	for (int i = m; i > 0; i--)
		cin >> a[i] >> b[i];

	vector<ll> ans(m + 1);

	ans[0] = (n * (n - 1)) / 2;

	vector<ll> land(n, 1);


	// �v�Z�ʂ�O(n)��O(nlogn)

	// �[���Ȃ���Ԃ���l����

	// union-find�؍쐬
	init(n);

	ll group = n;

	Rep(i, 1, m + 1) {
		if (same(a[i], b[i])) {
			// ���Ƃ��瑮���Ă�����X���[
			ans[i] = ans[i - 1];
			unite(a[i], b[i]); // �؂𕹍� �ꉞ
		}
		else {
			group--;
			if (group == 1) {
				unite(a[i], b[i]); // �؂𕹍�
				ans[i] = 0;
				break;
			}
			ans[i] = ans[i - 1] - land[find(a[i])] * land[find(b[i])]; // a�ɑ����Ă��鐔*b�ɑ����Ă��鐔������
			land[find(a[i])] += land[find(b[i])];
			land[find(b[i])] = land[find(a[i])];
			unite(a[i], b[i]); // �؂𕹍�
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}

	return 0;
}*/