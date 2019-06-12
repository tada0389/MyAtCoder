#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>

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
	return gcd(b, a % b);
}

// �ŏ����{��
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int ABC129Emain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string l;
	cin >> l;

	cout << l << endl;
	reverse(allof(l));
	cout << l << endl;

	ll ans = 0;
	vector<ll> num((int)l.size(), 0);
	num[0] = 1;
	Rep(i, 1, (int)l.size()) {
		num[i] = 3 * num[i - 1];
		num[i] %= mod;
	}
	while (1) {
		ll res = 1;

		/*Rep(i, 1, (int)l.size()) {
			sum = 2 * res; // 1 or 0
			sum %= mod;
			res += sum;
			res %= mod;
		}*/

		res = num[(int)l.size() - 1];

		// �ő�r�b�g�����ʂł��

		// �S��1�Ȃ�I��
		bool allone = true;
		rep(i, (int)l.size()) {
			if (l[i] == '0') {
				allone = false;
				break;
			}
		}
		if (allone) {
			res += 2 * res;
			res %= mod;
			ans += res;
			ans %= mod;
			break;
		}
		// �܂��A�ǂ��܂ł�1��
		int index = -1;
		for (int i = (int)l.size() - 2; i >= 0; i--) {
			if (l[i] == '1') {
				index = i;
				break;
			}
		}
		if (index == -1) {
			res -= num[(int)l.size() - 2];
			res *= 2;
			res %= mod;
			ans += res;
			ans %= mod;
			break;
		}

		l = l.substr(0, index + 1);

		ans += res;
		ans %= mod;
	}

	//ans += tmp;
	// �]��ł��邱�Ƃ�Y�ꂸ��
	cout << ans % mod << endl;
	return 0;
}
