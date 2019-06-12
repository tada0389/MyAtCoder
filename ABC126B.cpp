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
// 0~3‚Ü‚Å‚Í‰E¶‰ºã 4~7‚Ü‚Å‚ÍŽÎ‚ß
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// Å‘åŒö–ñ”
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Å¬Œö”{”
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int ABC126Bmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int s;
	cin >> s;

	// ŒŽ‚ð‚Ý‚é
	// Ž€‚à“ñ‚¯‚½
	int a = 0;
	a += s % 10;
	s /= 10;
	a += (s % 10) * 10;
	s /= 10;
	int b = 0;
	b += s % 10;
	s /= 10;
	b += (s % 10) * 10;

	bool canb = true;
	bool cana = true;
	if (b >= 13 || b == 0) canb = false;
	if (a >= 13 || a == 0) cana = false;

	if (cana && canb) {
		cout << "AMBIGUOUS" << endl;
		return 0;
	}
	else if (cana && !canb) {
		cout << "YYMM" << endl;
		return 0;
	}
	else if (!cana && canb) {
		cout << "MMYY" << endl;
		return 0;
	}
	else {
		cout << "NA" << endl;
		return 0;
	}

	return 0;
}
