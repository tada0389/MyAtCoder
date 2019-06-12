#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

int ABC118Amain() {
	int a, b;
	cin >> a >> b;

	bool yaku = false;

	for (int i = 1; i <= b; i++) {
		if (b % a == 0) {
			yaku = true;
			break;
		}
	}

	if (yaku) cout << a + b << endl;
	else cout << b - a << endl;
	return 0;
}