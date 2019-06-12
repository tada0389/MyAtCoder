#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int ABC116Dain() {
	// cin の高速化らしい
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> sushi;

	for (int i = 0; i < n; i++) {
		int t, d;
		cin >> t >> d;
		t--;
		sushi.push_back({ d, t });
	}
	sort(sushi.begin(), sushi.end()); // おいしさ順に昇順ソート
	reverse(sushi.begin(), sushi.end()); // 昇順から降順へ
	vector<bool> usd(n, false); // n個の配列にすべてfalse
	long long ans = 0;
	long long score = 0;
	int cnt = 0;
	// k個に選ばれなかった寿司達
	priority_queue<int> unused_repr;
	// k個に選ばれたが二個目以上だった寿司達
	// 小さいものから取り出せる優先度付きキュー
	priority_queue<int, vector<int>, greater<int>> used_subj;

	for (int i = 0; i < n; i++) {
		auto sus = sushi[i];
		int d = sus.first;
		int t = sus.second;
		if (usd[t]) {
			if (i < k) {
				score += d;
				// この種類が二個以上のときは消される予備軍として保管
				used_subj.push(d);
			}
		}
		else {
			usd[t] = true;
			if (i < k) {
				score += d + 2 * cnt + 1;
				cnt++;
			}
			else {
				// k+1番目以降の寿司で使われていないものは追加される予備軍として保管
				unused_repr.push(d);
			}
		}
	}

	ans = score;
	while (!unused_repr.empty() && !used_subj.empty()) {
		int repr = unused_repr.top();
		unused_repr.pop();
		int subj = used_subj.top();
		used_subj.pop();
		score += (long long)repr - subj + 2 * cnt + 1;
		cnt++;
		ans = max(ans, score);
	}
	cout << ans << endl;
	return 0;
}
