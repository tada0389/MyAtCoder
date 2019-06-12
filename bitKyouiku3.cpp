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

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

// 最小公約数
long lcm(long a, long b) {
	return a / gcd(a, b) * b;
}*/

int bitKyouiku3main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll h, w, k;
	cin >> h >> w >> k;

	// dp[i][j]:= jの高さでi番目にたどりつく可能性のある合計の本数
	// 2^7 = 128
	// 計算量 100 * 100 * 10 = 1e5 ちょうどいい
	vector<vector<ll>> dp(w, vector<ll>(h + 1, 0));

	dp[0][0] = 1;

	rep(j, h) {
		// 線を引く→隣は線を引けなくなる 全通りためす
		rep(i, w) {
			rep(bit, 1 << w - 1) {
				//cout << bit << endl;
				//bool next = true;
				bool can = true;
				// 数字が並んでたらアウト
				rep(l, w - 2) {
					//cout << (bit & (1 << i)) << " " << (bit & (1 << (i + 1)));
					if ((bit & (1 << l)) && (bit & (1 << (l + 1)))) {
						can = false;
						//cout << "ここでfalse";
					}
				}
				//cout << endl;
				if (!can) continue;

				/*
				// 同じのが紛れてる
				rep(i, w - 1) {
					if (bit & (1 << i)) {
						// 両端を入れ替える
						dp[i + 1][j + 1] += dp[i][j] % mod;
						//cout << j << "の高さで" << i << "と" << i + 1 << "を結ぶ";
						//next = false;
					}
					else {
						// そのまま下がる
						dp[i][j + 1] += dp[i][j] % mod;
						if (i == w - 2) // 最後の列だけ特別に処理
							dp[i + 1][j + 1] += dp[i + 1][j] % mod;
						//next = true;
						//cout << j << "の高さで" << i << "と" << i + 1 << "を結ばない";
					}
				}*/
				//cout << endl;

				if (i < w - 1 && (bit & (1 << i)))  dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
				else if (i >= 1 && (bit & (1 << (i - 1)))) dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % mod;
				else dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
			}
		}
	}

	//if (w == 1) cout << 1 << endl;
	//else 
	cout << dp[k - 1][h] % mod << endl;

	return 0;
}
