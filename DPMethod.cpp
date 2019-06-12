#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
/*
// change minimum aよりbの法が小さかったら、aの値をbの値に置き換える
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}

	return false;
}

// change maximum minimumの逆
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

// 一般的な流れ
/*
1.DP配列全体を「DPの種類に応じた初期値」で初期化
2.初期条件を入力
3.ループを回す
4.テーブルから解を得て出力
*/
/*
// k個以内でsを作れるかどうか
int one() {
	// 計算量が大きすぎる　改正
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;

	// ii 番目までの整数の中から kk 個の整数を選んで足した総和が jj とすることが可能かどうか
	vector<vector<int>> dp;
	dp = vector<vector<int>>(n + 1, vector<int>(s + 1, -1));

	// dp[i][j] i番目までのいくつか数字を加えたときの総和jにできるか
	// dp[i][j-a[i]]がtrueならdp[i+1][j]もtrue
	// dp[i][j]がtrueならdp[i+1][j]もtrue

	dp[0][0] = 0;
	int cnt = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i + 1][j] =  dp[i][j];
			if (j - a[i] >= 0) {
				chmin(dp[i + 1][j], dp[i][j - a[i]] + 1);
			}
		}

	}
	
	if (dp[n][s] == -1) cout << "NO" << endl;
	else {
		if (dp[n][s] <= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	// DPの添字ではなく、DPの値そのものに情報を持たせられないか
// 一般にbool値を求めるDPをすることは無駄が多く、同じ計算量でもっと多くのことを知ることができる
	// 具体的にはdp[n][A] <= K なら "YES"
	// dp[n][A] > K なら "NO" というように
}

// 個数制限なしナップサック問題
int two() {
	int n;
	int k;
	int w;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;

	// d[i+1][j]:i番目までの品物から主さの総和がj以下となるように選んだときの、価値の総和の最大値
	vector<vector<int>> dp;
	dp = vector<vector<int>>(n + 1, vector<int>(s + 1, -1));

	// 計算量半端なくなっちゃうけど...てことで修正
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) {
			for (int k = 0; k * a[i] <= j; k++){
				chmax(dp[i + 1][j], dp[i][j - k * a[i]] + k * 30);
			}
		}
	}
	// 以下本命　うえのだめ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) {
			if (j < a[i]) {
				dp[i + 1][j] = dp[i][j];
			}
			else {
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - a[i]] + v[i]);
			}
		}
	}

	cout << dp[n][w] << endl;
}

// 個数制限付きナップサック問題
void three() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> m(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> m[i];
	}
	// dp[i][j]:=i番目まででjを作る際に余る最大のi番目の個数(作れないときは-1)
	vector<vector<int>>dp;
	dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));

	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			
		}
	}
}

//ARC057B
int arc057bin() {
	int n, k;
	cin >> n >> k;
	vector<long long>a(n);
	vector<long long> sum(n + 1,0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	// dp[i][j]:=i日目まででj回機嫌が良かったときの勝利回数の最小値
	vector<vector<long long>> dp;
	dp = vector<vector<long long>>(n + 1, vector<long long>((n + 1), 10000000000));
	dp[0][0] = 0;

	if (sum[n] == k) {
		cout << 1 << endl;
		return 0;
	}
	/* 負けるときは徹底的に負ける　0syou
	   勝つときはぎりぎり機嫌をよくするように
	// 漸化式
	dp[i + 1][j] = dp[i][j]
	dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i][j] + (dp[i][j]+a[i+1])/s + 1 * pはその日の勝利数
	勝率 dp[i][j]/s < dp[i][j]+p/s+a[i+1]のときによくなる
	= p > (dp[i][j]+a[i+1])/sのとき 
	*/
/*
	// i日までの勝率 > i-1日までの勝率のとき機嫌良くする
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			// 勝たない
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			// 勝つ
			if (i == 0) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
			else {
				long long atleast = dp[i][j] * sum[i + 1] / sum[i] + 1;
				if (atleast <= a[i] + dp[i][j])
					dp[i + 1][j + 1] = min(dp[i][j + 1],atleast);
			}
		}
	}

	long long ans = 0;

	for (int j = n; j >= 0; j--) {
		if (dp[n][j] <= k) {
			ans = j;
			cout << ans << endl;
			return 0;
		}
	}

	//cout << ans << endl;
}

// 最長共通部分列問題
void four() {

}


void dfs(const vector<vector<int>> dp, const vector<pair<int, int>> item, int price, int i, vector<int> &selected) {
	if (i == 0 && price == 0) return;
	if (i < 0) return;
	for (int j = i - 1; j >= 0; j--) {
		if (price - item[j].first < 0) continue;
		if (dp[i][price] == dp[i][price - item[j].first] + item[j].second) {
			selected[j] = 1;
			dfs(dp, item, price - item[j].first, j, selected);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> item(n);
	rep(i, n) {
		cin >> item[i].first >> item[i].second;
	}


	// dp[i][j] := i番目までの荷物を見たときの、値段がjとなるカロリー
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	rep(i, n) {
		rep(j, k + 1) {
			if (j + item[i].first <= k) {
				dp[i + 1][j + item[i].first] = max(dp[i][j + item[i].first], dp[i][j] + item[i].second);
			}
			else
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}

	//cout << dp[n][k] << endl;
	int ans = dp[n][k];

	vector<int> selected(n, 0);

	//dfs(dp, item, k, n, selected);

	cout << ans << endl;
	rep(i, n) {
		cout << selected[i] << " ";
	}
	cout << endl;

	return 0;
}
*/