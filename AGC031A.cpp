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

int AGC031Amain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;

	// 飛ばし飛ばしでもよい

	typedef map<char, ll> M; // map<key の型, valueの型>
	M mp;

	rep(i, n) {
		mp[s[i]]++;
	}

	ll ans = 0;

	sort(allof(s)); // ソートしても変わらないのでは
	char tmpC = 'a';
	M alphaCnt;

	for (char c = 'a'; c <= 'z'; c++) {
		ll tmpAns = mp[c];
		for (char tc = 'a'; tc < tmpC; tc++) {
			tmpAns += (alphaCnt[tc] * mp[tmpC]) % mod;
			tmpAns %= mod;
		}
		alphaCnt[c] = tmpAns;
		tmpC++;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		ans += alphaCnt[c] % mod;
	}

	cout << ans % mod << endl;

	return 0;
}