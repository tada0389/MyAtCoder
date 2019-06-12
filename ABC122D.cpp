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
	return a * b / gcd(a, b);
}*/

// AG�����玟C�ȊO�A���̎���C�ȊO
// AC�����玟��G�ȊO
// AT�����玟��������GC�ȊO
// GA�����玟��C�ȊO


int ABC122Dmain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	// AGC, ACG, GAC�̕�������܂܂Ȃ�
	// AGTC, ATGC�̕�������܂܂Ȃ� (T�͂Ȃ�ł�����)
	// dp[3][2][1][i]:= i�����̍ő吔3,2,1�͈�O�̓���
	vector<vector<vector<vector<ll>>>> dp(4, vector<vector<vector<ll>>>(4, vector<vector<ll>>(4, vector<ll>(n + 1, 0))));
	// AGCT������ A = 0, G = 1, C = 2, T = 3;
	int first = 3;
	int second = 3;
	int third = 3;
	dp[first][second][third][0] = 1;
	Rep(i, 1, n + 1) {
		rep(d, 4) {
			rep(c, 4) {
				rep(b, 4) {
					rep(a, 4) {
						//if (dp[b][c][d][i - 1] == 0) continue;
						if (a == 0 && b == 1 && c == 2 ||
							a == 0 && b == 2 && c == 1 ||
							a == 1 && b == 0 && c == 2 ||
							a == 0 && b == 1 && d == 2 ||
							a == 0 && c == 1 && d == 2) { // �_���ȃp�^�[��
							continue;
						}
						else {
							dp[a][b][c][i] += dp[b][c][d][i - 1];
							dp[a][b][c][i] %= mod;
						}
					}
				}
			}
		}
	}

	ll sum = 0;
	rep(d, 4) {
		rep(c, 4) {
			rep(b, 4) {
				sum += dp[b][c][d][n];
				sum %= mod;
			}
		}
	}

	cout << sum % mod << endl;

	return 0;
}