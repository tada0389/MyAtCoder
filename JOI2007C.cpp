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

		//sort(a.begin(), a.end()); // �ꉞ�\�[�g�@�v�Z�ʂ��܂�H��Ȃ��̂�

		// �����S�񋓖@���g��
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
			temp += *(upper_bound(a.begin(), a.end(), aim)-1); // aim���傫���v�f�������ŏ��̗v�f����1�O�̗v�f��Ԃ�
			if (temp <= m) score = max(score, temp);
		}

		cout << score << endl;
	//}
		return 0;
}