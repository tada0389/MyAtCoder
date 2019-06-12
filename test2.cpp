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
#include <numeric>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int test2main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		int m;
		cin >> m;
		if (m == 0) break;
		vector<pair<int, int>>id(m);
		vector<vector<int>>score(m, vector<int>(10, 0));
		vector<vector<int>>eachScore(m);
		rep(i, m) {
			cin >> id[i].first;
			int num = 0;
			int point = 0;
			int cnt = 0;
			int tenNum = 0;
			while (num != 10) {
				if (num == 9) tenNum++;
				cnt++;
				int tmp;
				cin >> tmp;
				point += tmp;
				eachScore[i].push_back(tmp);

				if (tenNum == 3) {
					score[i][num] = point;
					break;
				}

				if (cnt == 2) {
					if (num == 9 && point >= 10) {
						continue;
					}
					score[i][num] = point;
					//cout << num << "番目に" << point << "はいる" << endl;
					cnt = 0;
					num++;
					point = 0;
				}
				else if (point == 10) {
					if (num == 9) continue;
					score[i][num] = point;
					if (cnt == 1) // ストライク
						score[i][num] += 10;
					//cout << num << "番目に" << point << "はいる" << endl;
					cnt = 0;
					num++;
					point = 0;
				}
			}
		}
		
		rep(i, m) {
			id[i].second = 0;
			int cnt = 0;
			int point = 0;
			int num = 0;
			rep(j, (int)eachScore[i].size()) {
				if (num == 9) {
					id[i].second += eachScore[i][j];
				}
				else {
					//cout << j << endl;
					point += eachScore[i][j];
					cnt++;
					if (point == 10) {
						// 10投目かどうか確かめる
						if (cnt == 1) {
							// ストライク
							for (int k = j + 1; k < (int)eachScore[i].size() && k < j + 3; k++) {
								id[i].second += eachScore[i][k]; // 次2回の投球をみる
							}
						}
						else { // スペア
							for (int k = j + 1; k < (int)eachScore[i].size() && k < j + 2; k++) {
								id[i].second += eachScore[i][k]; // 次の投球を見る
							}
						}
						id[i].second += point;
						point = 0;
						cnt = 0;
						num++;
					}
					if (cnt == 2) {
						id[i].second += point;
						cnt = 0;
						point = 0;
						num++;
					}
				}
			}
		}

		sort(allof(id), [&](const pair<int, int>& x, const pair<int, int>& y) {
			if (x.second == y.second) {
				return x.first < y.first;
			}
			return x.second > y.second;
		});
		
		rep(i, m) {
			cout << id[i].first << " " << id[i].second << endl;
		}
		/*rep(i, m) {
			cout << id[i].first << " ";
			rep(j, (int)eachScore[i].size()) {
				cout << eachScore[i][j] << " ";
			}
			cout << endl;
		}*/
	}

	return 0;
}
