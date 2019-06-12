#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int YahooBmain() {

	vector<vector<int>> path;
	path = vector<vector<int>>(4, vector<int>(4, 0));

	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		path[a][b]++;
		path[b][a]++;
	}

	vector<int> v;
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
	}

	bool flag = false;

	do {
		for (int i = 0; i < 3; i++) {
			if (path[v[i]][v[i + 1]] != 1) {
				break;
			}
			if (i == 2)
				flag = true;
		}
	} while (next_permutation(v.begin(), v.end()));

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}