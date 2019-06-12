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

int TenkaAmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int ans = inf;

	// ���ǔ��ƍ��ɕ�������

	// �ǂ��ŕ����邩

	// �ݐϘa
	vector<int> whiteNum(n + 1, 0);
	vector<int> blackNum(n + 1, 0);

	Rep(i, 1, n + 1) {
		int white = 0;
		int black = 0;
		if (s[i - 1] == '.') {
			white++;
		}
		else {
			black++;
		}
		whiteNum[i] = whiteNum[i - 1] + white;
		blackNum[i] = blackNum[i - 1] + black;
	}


	// �S�ʂ莎��
	Rep(i, 0 , n + 1) {
		int tmp = 0;
		tmp = blackNum[i] + whiteNum[n] - whiteNum[i];
		ans = min(tmp, ans);
	}

	cout << ans << endl;

	return 0;
}