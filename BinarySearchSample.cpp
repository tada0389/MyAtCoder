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
#include <math.h>
#include <list>

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


int binary_searchmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];

	// ��̂�A�_���[�W�A����B�_���[�W

	sort(allof(h), greater<ll>());

	// �ł�HP��������ɏW������

	// �S���Ƀ_���[�WB��ǂ킹
	// �����l�ɑ΂���ǉ��_���[�W��A - B�^����

	// �×~�@
	ll ans = 0;
	ll damage = 0;

	// T��̍U���őS�Ă̖�����|���邩�H
	// �|����ŏ���T��T��
	// T(i)���������Ă���Ȃ�T(i+1)���������@
	// 2���T��

	int left = 0;
	int right = h[0] / b;
	if (h[0] % b != 0) right++;
	int mid = (right + left) / 2;

	while (left < right) {
		//cout << "l, m, r = " << left << " " << mid << " " << right << endl;
		ll cnt = 0;
		rep(i, n) {
			if (h[i] > mid * b) {
				cnt += (ll)(h[i] - mid * b) / (a - b);
				if ((h[i] - mid * b) % (a - b) != 0) cnt++;
			}
		}
		//cout << cnt << endl;
		if (cnt > (ll)mid) {
			// �����ƍU���񐔂𑝂₷
			left = mid + 1;
			mid = (right + left) / 2;
		}
		else if (cnt < (ll)mid) {
			// �U���񐔂����炷
			right = mid - 1;
			mid = (right + left) / 2;
		}
		else { // �҂�����
			break;
		}
	}

	ll cnt = 0;
	rep(i, n) {
		if (h[i] > mid * b) {
			cnt += (ll)(h[i] - mid * b) / (a - b);
			if ((h[i] - mid * b) % (a - b) != 0) cnt++;
		}
	}
	if (cnt > (ll)mid) mid++;

	cout << mid << endl;

	return 0;
}
