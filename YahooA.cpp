#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int YahooAmain() {
	int n, k;
	cin >> n >> k;

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1)
			cnt++;
	}

	if (cnt >= k) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}