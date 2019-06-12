#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int ABC085Cmain() {
	int n, y;
	cin >> n >> y;

	int a, b, c;
	// a + b + c = n
	// a * 10000 + b * 5000 + c * 1000 = y@‚ª‚ ‚è“¾‚é‚©‚Ç‚¤‚©

	bool can = false;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			c = n - i - j;

			if (c >= 0 && i*10000+j*5000+c*1000 == y) {
				a = i;
				b = j;
				can = true;
				break;
			}
		}
		if (can)
			break;
	}
	
	if (can)
		cout << a << " " << b << " " << c << endl;
	else
		cout << "-1 -1 -1" << endl;
	return 0;
}