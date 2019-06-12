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
#include <numeric>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3Ç‹Ç≈ÇÕâEç∂â∫è„ 4~7Ç‹Ç≈ÇÕéŒÇﬂ
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// ç≈ëÂåˆñÒêî
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// ç≈è¨åˆî{êî
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

/*
// ëfàˆêîï™â pair.firstÇ≈ëfêîÅApair.secondÇ≈ëŒâûÇ∑ÇÈéwêî
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

const int MAX = 210000;

//ìÒçÄåWêîÇãÅÇﬂÇÈëOèàóù ÉeÅ[ÉuÉãÇçÏÇÈÅ@O(n)
// facÇÕäKèÊ
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

// ìÒçÄåWêîåvéZ
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m, k;
	cin >> n >> m >> k;
	COMinit();

	ll ans = 0;

	// â°ÇÇ›ÇÈ
	// nmCkí ÇËÇÃëgÇ›çáÇÌÇπÇ™Ç†ÇÈ
	ll eachNumRow = COM(n * m - 2, k - 2);
	// 2É}ÉXÇå≈íËÇ∑ÇÈ
	Rep(d, 1, n) {
		ans += (n - d) * d * m % mod * m % mod * eachNumRow % mod;
		ans %= mod;
	}

	Rep(d, 1, m) {
		ans += (m - d) * d * n % mod * n % mod * eachNumRow % mod;
		ans %= mod;
	}

	cout << ans % mod << endl;

	// modÇ≈äÑÇÈÇ±Ç∆ÇñYÇÍÇ∏Ç…
	return 0;
}
*/