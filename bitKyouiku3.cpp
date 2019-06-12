#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3�܂ł͉E������ 4~7�܂ł͎΂�
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// �ő����
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

// �ŏ�����
long lcm(long a, long b) {
	return a / gcd(a, b) * b;
}*/

int bitKyouiku3main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll h, w, k;
	cin >> h >> w >> k;

	// dp[i][j]:= j�̍�����i�Ԗڂɂ��ǂ���\���̂��鍇�v�̖{��
	// 2^7 = 128
	// �v�Z�� 100 * 100 * 10 = 1e5 ���傤�ǂ���
	vector<vector<ll>> dp(w, vector<ll>(h + 1, 0));

	dp[0][0] = 1;

	rep(j, h) {
		// �����������ׂ͐��������Ȃ��Ȃ� �S�ʂ肽�߂�
		rep(i, w) {
			rep(bit, 1 << w - 1) {
				//cout << bit << endl;
				//bool next = true;
				bool can = true;
				// ����������ł���A�E�g
				rep(l, w - 2) {
					//cout << (bit & (1 << i)) << " " << (bit & (1 << (i + 1)));
					if ((bit & (1 << l)) && (bit & (1 << (l + 1)))) {
						can = false;
						//cout << "������false";
					}
				}
				//cout << endl;
				if (!can) continue;

				/*
				// �����̂�����Ă�
				rep(i, w - 1) {
					if (bit & (1 << i)) {
						// ���[�����ւ���
						dp[i + 1][j + 1] += dp[i][j] % mod;
						//cout << j << "�̍�����" << i << "��" << i + 1 << "������";
						//next = false;
					}
					else {
						// ���̂܂܉�����
						dp[i][j + 1] += dp[i][j] % mod;
						if (i == w - 2) // �Ō�̗񂾂����ʂɏ���
							dp[i + 1][j + 1] += dp[i + 1][j] % mod;
						//next = true;
						//cout << j << "�̍�����" << i << "��" << i + 1 << "�����΂Ȃ�";
					}
				}*/
				//cout << endl;

				if (i < w - 1 && (bit & (1 << i)))  dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
				else if (i >= 1 && (bit & (1 << (i - 1)))) dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % mod;
				else dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
			}
		}
	}

	//if (w == 1) cout << 1 << endl;
	//else 
	cout << dp[k - 1][h] % mod << endl;

	return 0;
}
