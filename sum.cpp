#include <iostream>
#include <string>

using namespace std;

int Kain(void) {
	int k, s;

	cin >> k >> s;

	int cnt = 0;

	int z;

	for (int x = 0; x <= k; x++) {
		for (int y = 0; y <= k; y++) {
			z = s - x - y;
			if (z >= 0 && z <= k)
				cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}