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
#include <iomanip>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/


int ABC131Emain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	// ‚¿‚å‚¤‚ÇKŒÂ‚Â‚­‚Á‚Ä‚ ‚°‚é

	// –Ø\‘¢
	// ‚¢‚ç‚È‚¢•ª‚Íˆê–{‚ÉL‚Î‚µ‚Ä‚ ‚°‚é

	//‚Ü‚¸‚Å‚«‚é‚©
	ll sum = 0;
	rep(i, n - 1) sum += i;
	if (sum < k) {
		cout << -1 << endl;
		return 0;
	}

	// ˆê–{ü‚Å‚àÅ’Z‹——£2‚Í‘¶İ‚·‚é l - 2ŒÂ

	// ‚±‚±•Ï‚¦‚È‚«‚á
	if (true) {
		// •Â˜H‚ğì‚ç‚È‚«‚á‚¢‚¯‚È‚¢

		// ‚·‚×‚Ä‚ª’†S‚©‚ç‚Â‚È‚ª‚Á‚Ä‚¢‚é
		vector<pair<int, int>> ans;
		Rep(i, 1, n) {
			ans.push_back({ i + 1, 1 });
		}
		// ‚³‚ç‚É•Â˜H‚ğì‚Á‚Ä‚ ‚°‚é
		int tmp = sum;
		// ˆêŒÂˆêŒÂ‚Â‚È‚°‚é
		int i = 2;
		int j = 3;
		int m = n - 1;
		while (tmp != k) {
			ans.push_back({ i, j });
			j++;
			if (j > n) {
				i++;
				j = i + 1;
			}
			tmp--;
			m++;
		}

		cout << m << endl;
		rep(l, m) {
			cout << ans[l].first << " " << ans[l].second << endl;
		}

		return 0;
	}

	int index = -1;
	// kŒÂ‘¶İ‚·‚é
	// ‰½’¸“_‚Åì‚é‚©‘S’Tõ
	Rep(i, 3, n + 1) {
		ll first = 0;
		rep(j, i - 1) {
			first += j;
		}
		ll second = 0;
		second = n - (i - 2) - 2;

		//cout << first + second << endl;
		if (first + second == k) {
			index = i;
			break;
		}
	}

	if (index == -1) { // ‚±‚±‚ÍŠÖŒW‚È‚©‚Á‚½ â‘Î‚Å‚«‚é
		cout << -1 << endl;
		return 0;
	}

	// ƒOƒ‰ƒt‚ğì‚Á‚Ä‚ ‚°‚é
	ll m = n - 1;
	vector<pair<int, int>> ans;
	// ‚Ü‚¸index‚ÌŒÂ”
	// ’†‰›‚ğ1‚É‚·‚é
	Rep(i, 1, index) {
		ans.push_back({ i + 1, 1 });
	}

	// Ÿ‚Éˆê”Ô‘å‚«‚¢“_‚©‚çL‚Î‚µ‚Ä‚ ‚°‚é
	Rep(i, index, n) {
		ans.push_back({ i, i + 1 });
	}

	cout << m << endl;
	rep(i, m) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}
