#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int JOImain() {
	int n, m;

	//while (true) {

		cin >> n >> m;
		//if (n == 0 && m == 0)
			//break;

		vector<int> a;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			a.push_back(p);
		}

		//sort(a.begin(), a.end()); // 一応ソート　計算量あまり食わないので

		// 半分全列挙法を使う
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int x;
				x = a[i] + a[j];
				a.push_back(x);
			}
		}

		a.push_back(0);
		sort(a.begin(), a.end());

		int score = 0;
		for (int i = 0; i < a.size(); i++) {
			int temp = a[i];
			int aim = m - a[i];
			if (aim < 0) continue;
			temp += *(upper_bound(a.begin(), a.end(), aim)-1); // aimより大きい要素が現れる最初の要素から1つ前の要素を返す
			if (temp <= m) score = max(score, temp);
		}

		cout << score << endl;
	//}
		return 0;
}