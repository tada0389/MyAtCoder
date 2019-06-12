#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

int ABC118Bmain() {
	int n, m;
	cin >> n >> m;
	vector<int> k(n);
	vector<vector<int>> a;
	a = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> suki(m+1, 0);

	// D‚«‚¾‚Æ“š‚¦‚½”
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k[i]; j++) {
			suki[a[i][j]]++;
		}
	}

	int cnt = 0;

	for (int i = 0; i <= m; i++) {
		if (suki[i] == n) cnt++;
	}

	cout << cnt << endl;

	return 0;
}