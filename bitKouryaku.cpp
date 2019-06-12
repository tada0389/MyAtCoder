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

	long long res = 1 << 29; // 2^29 infinityとほぼ同義だと思われ

	// ボーナスの取り方を2^10通り試す
	// 例えば 011101101の時は1,3,4,6,7,8番目の問題を全完する
	for (int bit = 0; bit < (1 << d); bit++) {
		long long sum = 0;
		long long num = 0;
		for (int i = 0; i < d; i++) {
			if (bit & (1 << i)) { // 110110101(bit) と 1000(i=3) の論理積など
				sum += c[i] + p[i] * 100 * (i + 1);
				num += p[i];
			}
		}
		if (sum >= g) res = min(res, num);
		else { // cが(ほとんど)関係しない端数 // 関係しても関係ない
			for (int i = d - 1; i >= 0; i--) {
				if (bit & (1 << i)) continue; // すでに全完されている問題は飛ばす
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