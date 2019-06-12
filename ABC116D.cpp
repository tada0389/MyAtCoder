#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int ABC116Dain() {
	// cin �̍������炵��
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
	sort(sushi.begin(), sushi.end()); // �����������ɏ����\�[�g
	reverse(sushi.begin(), sushi.end()); // ��������~����
	vector<bool> usd(n, false); // n�̔z��ɂ��ׂ�false
	long long ans = 0;
	long long score = 0;
	int cnt = 0;
	// k�ɑI�΂�Ȃ��������i�B
	priority_queue<int> unused_repr;
	// k�ɑI�΂ꂽ����ڈȏゾ�������i�B
	// ���������̂�����o����D��x�t���L���[
	priority_queue<int, vector<int>, greater<int>> used_subj;

	for (int i = 0; i < n; i++) {
		auto sus = sushi[i];
		int d = sus.first;
		int t = sus.second;
		if (usd[t]) {
			if (i < k) {
				score += d;
				// ���̎�ނ���ȏ�̂Ƃ��͏������\���R�Ƃ��ĕۊ�
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
				// k+1�Ԗڈȍ~�̎��i�Ŏg���Ă��Ȃ����̂͒ǉ������\���R�Ƃ��ĕۊ�
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
