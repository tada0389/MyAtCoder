#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <math.h>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

typedef long long ll;
const int inf = 1e9 + 7;
//const ll infll = 1 << 60;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

// 型による変数のオーバーフローに気をつけろ！！
// 悩んだら図やグラフを書け！！悩む前から書け！！

/*
int n, a, b, c;
vector<int> l;

int dfs(int sum,int anum, int bnum, int cnum) {
	//cout << sum  << " " << anum << " " << bnum << " " << cnum<< endl;
	if (sum == n) {
		if (min(anum, bnum) == 0 || cnum == 0) return inf;
		return abs(a - anum) + abs(b - bnum) + abs(c - cnum) - 30;
	}

	int goNothing = dfs(sum + 1, anum, bnum, cnum);
	int goA = dfs(sum + 1, anum + l[sum], bnum, cnum) + 10;
	int goB = dfs(sum + 1, anum, bnum + l[sum], cnum) + 10;
	int goC = dfs(sum + 1, anum, bnum, cnum + l[sum]) + 10;

	int m = min(goNothing, goA);
	m = min(m, goB);
	//cout << m << endl;
	return min(m, goC);
}

int ABC119Cmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	//int a, b, c;
	cin >> n >> a >> b >> c;
	rep(i, n) {
		int temp;
		cin >> temp;
		l.push_back(temp);
	}

	// 全探索する
	int ans = dfs(0, 0, 0, 0);
	cout << ans << endl;

	
	return 0;
}*/