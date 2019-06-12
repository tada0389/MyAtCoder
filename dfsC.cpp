#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;
/*
vector<vector<char>> field;
vector<vector<int>> landNum;

void dfs(int x, int y, int num) {
	field[x][y] = 'x';
	landNum[x][y] = num;

	for (int dx = -1; dx <= 1; dx++) {
		if (field[dx + x][y] == 'o') {
			dfs(dx + x, y, num);
		}
	}
	for (int dy = -1; dy <= 1; dy++) {
		if (field[x][dy + y] == 'o') {
			dfs(x, dy + y, num);
		}
	}
}

int dfsmain() {
	field = vector<vector<char>>(12,vector<char>(12,'x'));
	landNum = vector<vector<int>>(12, vector<int>(12,0));
	vector<int> n;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> field[i][j];
		}
	}

	int num = 0;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (field[i][j] == 'o') {
				//cout << "(x,y): " << i << "," << j << endl;
				num++;
				dfs(i, j, num);
				n.push_back(num);
			}
		}
	}

	bool flag = false;

	// landNum‚Ì‚·‚×‚Ä‚ÉÚG‚·‚é“_‚ª‚ ‚é‚©l‚¦‚é
	for (int i = 1; i <= 10; i++){
		if (flag) break;
		for (int j = 1; j <= 10; j++) {
			//cout << landNum[i][j];
			if (landNum[i][j] == 0){
				for (int k = 0; k < n.size(); k++) {
					//cout << n[k] << endl;
					if (landNum[i - 1][j] == n[k] ||
						landNum[i][j - 1] == n[k] ||
						landNum[i + 1][j] == n[k] ||
						landNum[i][j + 1] == n[k]) {
						if (n[k] == num)
							flag = true;
					}
					else break;
				}
			}
		}
		//cout << endl;
	}

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}*/