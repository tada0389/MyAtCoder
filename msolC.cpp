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
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}


// ‘fˆö”•ª‰ğ pair.first‚Å‘f”Apair.second‚Å‘Î‰‚·‚éw”
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

//“ñ€ŒW”‚ğ‹‚ß‚é‘Oˆ— ƒe[ƒuƒ‹‚ğì‚é@O(n)
// fac‚ÍŠKæ
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

// “ñ€ŒW”ŒvZ
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	COMinit();

	ll ans = 0;

	vector<ll> panum(2 * n), qanum(2 * n);
	vector<ll> pbnum(2 * n), qbnum(2 * n);
	panum[0] = 1;
	qanum[0] = 1;
	pbnum[0] = 1;
	qbnum[0] = 1;

	Rep(i, 1, n * 2) {
		panum[i] = panum[i - 1] * a;
		panum[i] %= mod;
		qanum[i] = qanum[i - 1] * 100LL;
		qanum[i] %= mod;

		pbnum[i] = pbnum[i - 1] * b;
		pbnum[i] %= mod;
		qbnum[i] = qbnum[i - 1] * 100LL;
		qbnum[i] %= mod;
	}

	ll pasum = 0;
	ll qasum = 0;

	// ‚‹´‚ªŸ‚Âê‡
	rep(i, n) {
		// i‚ÍÂ–Ø‚ÌŸ‚Â‰ñ”
		ll p, q;
		p = 1;
		q = 1;
		p *= COM(n, i);
		p *= panum[n];
		p %= mod;
		p *= pbnum[i];
		p %= mod;
		p *= (n + i);
		p %= mod;

		q *= qanum[n];
		q %= mod;
		q *= qbnum[i];
		q %= mod;

		// ‡”‚Í n + i ‰ñ
		pasum += p;
		qasum += q;
		pasum %= mod;
		qasum %= mod;
	}

	ll pbsum = 0;
	ll qbsum = 0;

	// Â–Ø‚ªŸ‚Âê‡
	rep(i, n) {
		// i‚Í‚‹´‚ÌŸ‚Â‰ñ”
		ll p, q;
		p = 1;
		q = 1;
		p *= COM(n, i);
		p *= pbnum[n];
		p %= mod;
		p *= panum[i];
		p %= mod;
		p *= (n + i);
		p %= mod;

		q *= qbnum[n];
		q %= mod;
		q *= qanum[i];
		q %= mod;

		// ‡”‚Í n + i ‰ñ
		pbsum += p;
		qbsum += q;
		pbsum %= mod;
		qbsum %= mod;
	}

	cout << pbsum << " " << qbsum << endl;
	// •ª•ê‚ğ‡‚í‚¹‚é
	ll q = lcm(qasum, qbsum);
	ll p = pasum * (q / qasum) + pbsum * (q / qbsum);
	q *= 100 - c;
	p *= 100;
	p %= mod;
	q %= mod;

	cout << p << " " << q << endl;



	ll g = gcd(p, q);
	p /= g;
	q /= g;
	cout << p << " " <<  q << endl;

	return 0;
}
*/