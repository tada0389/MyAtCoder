#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
/*
using namespace std;

typedef long long ll;

ll n;
ll ans = 0;

// ‚Å‚«‚é‚¾‚¯‘‚â‚·”‚¦‚é
ll check(ll tmp) {
	//cout << tmp << endl;
	int cnt = 1;
	while (tmp % 2 == 0) {
		cnt++;
		tmp /= 2;
	}
	bool find = false;
	while (cnt >= 2) {
		ll ttmp = tmp;
		//cout << ttmp << endl;
		while (ttmp % 10 == 2 || ttmp % 10 == 8) {
			ttmp /= 10;
			//cout << ttmp << endl;
			if (ttmp == 0) {
				//cout << "ok" << endl;
				find = true;
			}
		}
		if (find) break;
		cnt--;
		tmp *= 2;
	}
	//cout << cnt << endl;
	return cnt;
}

bool waru(int dig) {
	for (ll bit = 0; bit < (1 << dig); bit++) {
		ll tmp = 0;
		for (int i = dig - 1; i >= 0; i--) {
			if (bit & (1 << i)) {
				tmp += 2 ;
			}
			else {
				tmp += 8;
			}
			tmp *= 10;
			//cout << tmp << endl;
		}
		tmp /= 10;
		//cout << tmp << endl;
		if (n % tmp) {
			n /= tmp;
			ans += check(tmp);
		}
	}
	return true;
}

int main() {
	cin >> n;

	for (int i = 17; i >= 1; i--) {
		if (waru(i) == false) {
			cout << -1 << endl;
		}
	}

	cout << ans << endl;

	return 0;
}*/