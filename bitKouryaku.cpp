#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;
/*
int d, g;
vector<int>p;
vector<int>c;

int bitmain(){
	cin >> d >> g;
	vector<int>p;
	vector<int>c;
	for (int i = 0; i < d; i++) {
		int pi, ci;
		cin >> pi >> ci;
		p.push_back(pi);
		c.push_back(ci);
	}

	long long res = 1 << 29; // 2^29 infinity�Ƃقړ��`���Ǝv���

	// �{�[�i�X�̎�����2^10�ʂ莎��
	// �Ⴆ�� 011101101�̎���1,3,4,6,7,8�Ԗڂ̖���S������
	for (int bit = 0; bit < (1 << d); bit++) {
		long long sum = 0;
		long long num = 0;
		for (int i = 0; i < d; i++) {
			if (bit & (1 << i)) { // 110110101(bit) �� 1000(i=3) �̘_���ςȂ�
				sum += c[i] + p[i] * 100 * (i + 1);
				num += p[i];
			}
		}
		if (sum >= g) res = min(res, num);
		else { // c��(�قƂ��)�֌W���Ȃ��[�� // �֌W���Ă��֌W�Ȃ�
			for (int i = d - 1; i >= 0; i--) {
				if (bit & (1 << i)) continue; // ���łɑS������Ă�����͔�΂�
				for (int j = 0; j < p[i]; j++) {
					if (sum >= g) break;
					sum += 100 * (i + 1);
					num++;
				}
			}
			res = min(res, num);
		}
	}

	cout << res << endl;

	return 0;
}*/