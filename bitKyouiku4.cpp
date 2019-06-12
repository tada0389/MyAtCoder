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

int bitkyouiku4main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll ans = 0;

	// ��ʃr�b�g����X��K�����߂Ĉ�v���Ȃ���������d�Ƃ���
	for (int d = 40; d >= -1; d--) {
		if (d != -1 && !(k & (1LL << d))) continue;

		ll tmp = 0;
		// 40bit���ׂČv�Z����
		for (int e = 40; e >= 0; e--) {
			ll mask = 1LL << e;
			ll num = 0;
			// a[i]��i�r�b�g�ڂ�1�ł���������߂Ă���
			for(int i = 0; i < n; i++)
				if(a[i] & mask) num++;

			if (e > d) { // k�̒l�ɍ��킹��
				if (k & mask) tmp += mask * (n - num);
				else tmp += mask * num;
			}
			else if (e == d) { // 0�Ƃ���
				tmp += mask * num;
			}
			else {// 0��1�̑I���ɗ]�T������Ȃ瑝�������I��
				tmp += mask * max(num, n - num);
			}
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}