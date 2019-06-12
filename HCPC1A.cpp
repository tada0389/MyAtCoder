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

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1 << 60LL;
const ll mod = 1e9 + 7;
// 0~3�܂ł͉E������ 4~7�܂ł͎΂�
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

// �^�ɂ��ϐ��̃I�[�o�[�t���[�ɋC������I�I
// �Y�񂾂�}��O���t�������I�I�Y�ޑO���珑���I�I

int HCPC1Amain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<ll> c(n);
	rep(i, n - 1) cin >> c[i+1];
	// c�̓}�C�i�X������

	vector<ll> x(n, -1);

	// dp[i]:=i�����܂ł̍ő�l
	vector<ll>ap(n+1, 0);
	vector<ll>tp(n+1, 0); // �ۑ��p ���ׂĒʂ�
	ap[0] = 0;
	tp[0] = 0;
	for (int i = 1; i < n; i++) {
		tp[i] = tp[i - 1] + c[i];
		if (c[i] > 0) {
			ap[i] = ap[i-1] + c[i];
		}
		else {
			ap[i] = max(ap[i - 1] + c[i], 0LL);
		}
	}

	vector<ll>rap(n + 1, 0);
	vector<ll>rtp(n + 1, 0);
	rap[n] = 0;
	rtp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		rtp[i] = tp[i + 1] + c[i];
		if (c[i] > 0) {
			ap[i] = ap[i + 1] + c[i];
		}
		else {
			ap[i] = max(ap[i + 1] + c[i], 0LL);
		}
	}

	rep(i, n) {
		ll tMax = -1;
		// ���ƉE��2�p�^�[��
		/*if (i == 0) {
			x[i] = ap[n-1];
		}
		else if (i == n) {
			x[i] = tap[0];
		}
		{*/
			// �E
			tMax = max(tMax, ap[i]);
			// ��
			tMax = max(tMax, rap[i]);

			x[i] = tMax;
		//}
	}

	rep(i, n) {
		cout << x[i] << endl;
	}

	return 0;
}