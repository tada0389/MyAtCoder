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

int bitkyouiku4main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll ans = 0;

	// 上位ビットからXとKが初めて一致しなかった桁をdとする
	for (int d = 40; d >= -1; d--) {
		if (d != -1 && !(k & (1LL << d))) continue;

		ll tmp = 0;
		// 40bitすべて計算する
		for (int e = 40; e >= 0; e--) {
			ll mask = 1LL << e;
			ll num = 0;
			// a[i]のiビット目が1である個数を求めている
			for(int i = 0; i < n; i++)
				if(a[i] & mask) num++;

			if (e > d) { // kの値に合わせる
				if (k & mask) tmp += mask * (n - num);
				else tmp += mask * num;
			}
			else if (e == d) { // 0とする
				tmp += mask * num;
			}
			else {// 0か1の選択に余裕があるなら増える方を選択
				tmp += mask * max(num, n - num);
			}
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}