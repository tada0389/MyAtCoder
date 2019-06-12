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
#include <iomanip>

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
	return a / gcd(a, b) * b;
}*/
/*
double dp[302][302][302];
int n;

double rec(int i, int j, int k) {
	if (dp[i][j][k] >= 0) return dp[i][j][k];
	if (i == 0 && j == 0 && k == 0) return 0.0;

	double res = 0.0;
	// 1枚のが減る
	if (i > 0) res += rec(i - 1, j, k) * i;
	// 2
	if (j > 0) res += rec(i + 1, j - 1, k) * j;
	if (k > 0) res += rec(i, j + 1, k - 1) * k;
	res += n;
	// 最後にまとめてかける
	res *= 1.0 / (i + j + k);
	return dp[i][j][k] = res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	double ans = 1.0;

	// dp[i][j][k];=残りの皿の数が0枚の個数がi個，1枚がj，2枚がk個
	// からすべての寿司がなくなるまでの操作回数の期待値

	rep(i, n + 1) {
		rep(j, n + 1) {
			rep(k, n + 1) {
				dp[i][j][k] = -1;
			}
		}
	}
	vector<int> num(3, 0);
	rep(i, n) {
		num[a[i] - 1]++;
	}

	cout << fixed << setprecision(10) << rec(num[0],num[1],num[2]) << endl;

	return 0;
}
*/