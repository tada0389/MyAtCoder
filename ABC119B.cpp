#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1 << 60LL;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

// 型による変数のオーバーフローに気をつけろ！！
// 悩んだら図やグラフを書け！！悩む前から書け！！

int ABC119Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<long double> x(n);
	vector<string> u(n);
	rep(i, n) {
		cin >> x[i] >> u[i];
	}

	long double sum = 0;
	rep(i, n) {
		if (u[i] == "BTC") {
			sum += x[i] * 380000;
		}
		else {
			sum += x[i];
		}
	}

	cout << sum << endl;

	return 0;
}