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

	// IđPFRXgPÁīĩÄęâˇ
	// IđQFRXgQÁīĩÄb-aâˇ

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