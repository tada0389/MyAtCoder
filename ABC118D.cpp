#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

int ABC118Dmain() {
	int c[] = {1000,2,5,5,4,5,6,3,7,6 };

	int n, m;
	cin >> n >> m;
	vector<int>a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	vector<long long> dp(n+1,-1); // n–{g‚Á‚½‚Ìì‚Á‚½Œ…‚Ì”
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (i - c[a[j]] >= 0) {
				dp[i] = max(dp[i], dp[i - c[a[j]]] + 1); 

			}
		}
	}

	vector<long long> ans(dp[n], 0);

	long long num = n;
	for (int j = 0; j < dp[n]; j++) {
		for (int i = 0; i < m; i++) {
			if (num - c[a[i]] >= 0) {
				if (dp[num - c[a[i]]] == (dp[num] - 1)) {
					ans[j] = a[i];
					num -= c[a[i]];
					break;
				}
			}
		}
	}

	for (int i = 0; i < dp[n]; i++) {
		cout << ans[i];
	}

	cout << endl;

	return 0;
}