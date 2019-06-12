#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*
int main() {
	int n, k; // nは商品数，kは可能な合計金額
	cin >> n >> k;
	vector<pair<int, int>> item(n); // 商品情報，firstに値段，secondにカロリー
	for (int i = 0; i < n; i++) {
		cin >> item[i].first >> item[i].second;
	}


	// dp[i][j] := i番目までの荷物を見たときの、値段がjとなるカロリー
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k + 1; j++) {
			if (j - item[i].first >= 0) {
				dp[i + 1][j] = max(dp[i][j],
					dp[i][j - item[i].first] + item[i].second);
			}
			else
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}

	int ans = dp[n][k];
	cout << "可能なカロリーの最大値" << endl;
	cout << ans << endl;

	return 0;
}
*/