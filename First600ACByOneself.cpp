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
#include <list>

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
}
*/

/*
// 素因数分解 pair.firstで素数、pair.secondで対応する指数
vector<pair<long long, long long> > prime_factorize(long long n) {
	vector<pair<long long, long long> > res;
	for (long long p = 2; p * p <= n; ++p) {
		if (n % p != 0) continue;
		int num = 0;
		while (n % p == 0) { ++num; n /= p; }
		res.push_back(make_pair(p, num));
	}
	if (n != 1) res.push_back(make_pair(n, 1));
	return res;
}

const int MAX = 110000;

//二項係数を求める前処理 テーブルを作る　O(n)
// facは階乗
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

// 二項係数計算
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	COMinit();
	vector<ll> a(n + 1);
	// 重複している点を探す
	vector<int> num(n + 1, 0);
	int doubleNum;
	rep(i, n + 1) {
		cin >> a[i];
		num[a[i]]++;
		if (num[a[i]] == 2) doubleNum = a[i];
	}
	// 一つだけ同じ数字が2つある
	// 長さi(1~n + 1)の部分列をそれぞれ書き下す

	// もし重複がなければ？
	// ans = (n + 1) C i

	vector<int> index;
	rep(i, n + 1) {
		if (a[i] == doubleNum)
			index.push_back(i);
	}

	int na, nb, nc;
	na = index[0];
	nb = index[1] - index[0] - 1;
	nc = n + 1 - index[1] - 1;

	Rep(length, 1, n + 2) {
		// 長さlengthの部分列
		ll ans;
		if (length == 1) {
			cout << n << endl;
			continue;
		}
		ans = COM(n - 1, length) % mod;
		// 左の点が入ってるとき
		ans += COM(n - 1, length - 1);
		ans %= mod;
		// 右の点が入っているとき
		  // nbの値がない場合はna, ncの値は被る
		ans += COM(n - 1, length - 1);
		ans %= mod;
		ans = (ans - COM(na + nc, length - 1) + mod) % mod;
		// 両方入っているとき
		ans += COM(n - 1, length - 2);
		ans %= mod;

		cout << ans << endl;
	}

	return 0;
}
*/