#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int YahooCmain() {
	long long k, a, b;
	cin >> k >> a >> b;

	// 選択肢１：コスト１消費して一枚増やす
	// 選択肢２：コスト２消費してb-a枚増やす

	long long res = 1;
	long long cnt;

	cnt = k;

	if (b - a >= 3) {
		if (res < a) {
			res += a - 1;
			cnt -= a - 1;
		}
		if (cnt % 2 == 1) {
			res += 1;
			cnt -= 1;
		}
		if (cnt % 2 == 0) {
			res += (b - a) * (cnt / 2);
		}
	}
	else {
		res += k;
	}

	cout << res << endl;

	return 0;
}