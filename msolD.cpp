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
#define MAX_V 10010

vector<pair<ll, ll>> G[MAX_V];

// �_�C�N�X�g���@
vector<ll> dijkstra(ll start) {
	vector<ll> dist(MAX_V, infll);
	dist[start] = 0; // dist[i] := start->i�܂ł̍ŒZ����
	priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
	que.push({ 0, start });
	while (!que.empty()) {
		ll cost, u; // ���܂łɂ����������ԁ@���݂̒��_
		cost = que.top().first, u = que.top().second;
		que.pop();
		if (dist[u] < cost) continue;
		for (auto tmp : G[u]) {
			ll v = tmp.first, time = tmp.second; // �אڂ��钸�_�A���̒��_�܂ōs������
			if (dist[v] > dist[u] + time) {
				dist[v] = dist[u] + time;
				que.push({ dist[v], v });
			}
		}
	}
	return dist;
}

int n;
ll ans[MAX_V];
ll cnt = 0;
ll c[MAX_V];
bool used[MAX_V];

void dfs(int s) {
	if (used[s] == true) return;
	ans[s] = c[cnt++];
	used[s] = true;

	// ���Ƀm�[�h���̑����ӂ��ɂ��
	sort(allof(G[s]), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
		return (int)G[a.first].size() > (int)G[b.first].size();
	});
	rep(i, (int)G[s].size()) {
		dfs(G[s][i].first);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	vector<ll> a(n - 1), b(n - 1), tmpC(n);
	rep(i, n - 1) {
		cin >> a[i] >> b[i];
		G[a[i] - 1].push_back({ b[i] - 1, 0 });
		G[b[i] - 1].push_back({ a[i] - 1, 0 });
	}
	rep(i, n) cin >> tmpC[i];
	rep(i, n) used[i] = false;

	// ���j�Ƃ��ẮA�ӂ��������_�ɑ傫���l��^������
	// n��1e4�Ȃ̂Ŕ�r�I������ ������������O(n^2)��������


	sort(allof(tmpC), greater<ll>());
	rep(i, n) {
		c[i] = tmpC[i];
	}
	
	vector<pair<ll, ll>> num(n);
	rep(i, n) num[i].second = i;

	// �ׂ̕ӂƂ̍����ł��邾�����������������������
	rep(i, n) {
		num[i].first = (int)G[i].size();
	}

	sort(allof(num), greater<pair<ll, ll>>());
	
	int maxIndex = 0;
	int maxNum = 0;
	rep(i, n) {
		if (maxNum < (int)G[i].size()) {
			maxNum = (int)G[i].size();
			maxIndex = i;
		}
	}

	dfs(maxIndex);

	ll res = 0;

	rep(i, n - 1) {
		// �ӂ�S�ʂ�݂�
		ll mi;
		mi = min(ans[a[i] - 1], ans[b[i] - 1]);
		res += mi;
	}

	cout << res << endl;
	rep(i, n) cout << ans[i] << " ";
	cout << endl;


	return 0;
}
*/