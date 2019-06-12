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

int LongestPathmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n, vector<int>());
	vector<int> h(n, 0); // ������

	rep(i, m) {
		int x, y;
		cin >> x >> y;
		G[x - 1].push_back(y - 1);
		h[y - 1]++;
	}

	// ��������g�|���W�J���\�[�g
	// �ړ��悪�Ȃ��_��ۑ�����
	stack<int> st;
	rep(i, n) if (h[i] == 0) st.push(i);
	// �\�[�g��̃O���t
	vector<int> sortG;

	while (!st.empty()) {
		int i = st.top(); st.pop();
		sortG.push_back(i);
		for (auto& j : G[i]) {
			// �אڂ��钸�_�̓�������-1
			h[j]--;
			if (h[j] == 0) st.push(j);
		}
	}

	// ��������DP
	vector<int> dp(n + 1, 0);
	rep(i, n) {
		int from = sortG[i];
		rep(j, (int)G[from].size()) {
			int to = G[from][j];
			dp[to] = max(dp[to], dp[from] + 1);
		}
	}

	cout << *max_element(allof(dp)) << endl;

	return 0;
}
