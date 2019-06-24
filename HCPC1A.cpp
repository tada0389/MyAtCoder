#include <iostream>
#include <cstdio>
#include <string>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> have(14, 0);

bool dfs(int left, int right, int turn, int myCnt, int yourCnt) {
	//cout << left << " " << right << " " << turn << " " << myCnt << " " << yourCnt << endl;
	if (myCnt == 6) return true;
	if (yourCnt == 6) return false;
	//if (left == 0 && right == 14) return (turn == 1) ? true : false;
	// turn = 0‚ÅŽ©•ª‚Ì”Ô
	bool win = false;
	if (turn == 0) {
		bool can = false;
		if (left != 0)
			if (have[left] == 1) {
				win = dfs(left - 1, right, 1 - turn, myCnt + 1, yourCnt);
				can = true;
			}
		if (win) return true;
		if (right != 14)
			if (have[right] == 1) {
				win = dfs(left, right + 1, 1 - turn, myCnt + 1, yourCnt);
				can = true;
			}
		if (!can) win = dfs(left, right, 1 - turn, myCnt, yourCnt);
	}
	else {
		bool can = false;
		win = true;
		if (left != 0)
			if (have[left] == 0) {
				win = dfs(left - 1, right, 1 - turn, myCnt, yourCnt + 1);
				can = true;
			}
		if (!win) return false;
		if (right != 14)
			if (have[right] == 0) {
				win = dfs(left, right + 1, 1 - turn ,myCnt, yourCnt + 1);
				can = true;
			}
		if (!can) win = dfs(left, right, 1 - turn, myCnt, yourCnt);
	}

	return win;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> f(n, vector<int>(6));
	for(int j = 0; j < n; j++)
		for (int i = 0; i < 6; i++) cin >> f[j][i];

	for (int i = 0; i < n; i++) {
		// ‘ŠŽè‚ÌƒJ[ƒh‚à‚í‚©‚é 6 + 6 + 1 = 13‚Ì‚½‚ß
		bool win = false;

		//sort(f.begin(), f.end());
		/*
		// æŽè‚¾‚©‚çŸ‚Ä‚éê‡
		for (int j = 1; j <= 6; j++) {
			if (f[i][j - 1] != j) break;
			if (j == 6) {
				cout << "yes" << endl;
				win = true;
			}
		}
		for (int j = 8; j <= 13; j++) {
			if (f[i][j - 8] != j) break;
			if (j == 13) {
				cout << "yes" << endl;
				win = true;
			}
		}

		if (win) continue;
		*/

		for (int j = 1; j <= 13; j++) have[j] = 0;
		for (int j = 0; j < 6; j++) {
			have[f[i][j]] = 1;
		}
		win = dfs(6, 8, 0, 0, 0);

		if (win) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}