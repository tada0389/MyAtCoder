#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> allPath(0, vector<int>());
vector<vector<pair<int, int>>> G(101, vector<pair<int, int>>());
int d;
int a[510], b[510], f[510];

void bfs(int next, vector<int> path, vector<bool> used) {
	if (next == d - 1) {
		allPath.push_back(path);
	}
	used[next] = true;
	//cout << next << endl;
	
	for (int i = 0; i < (int)G[next].size(); i++) {
		if (used[G[next][i].first]) continue;
		auto tmp = path;
		auto usedTmp = used;
		tmp.push_back(G[next][i].first);
		bfs(G[next][i].first, tmp, usedTmp);
	}
}

int main() {
	int c, n, m, s;
	cin >> c >> n >> m >> s >> d;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> f[i];
		G[a[i] - 1].push_back({ b[i] - 1, f[i] });
		G[b[i] - 1].push_back({ a[i] - 1, f[i] });
	}

	vector<bool> used(n, false);
	vector<int> path(s - 1);
	bfs(s - 1, path, used);

	for (int i = 0; i < (int)allPath.size(); i++) {
		for (int j = 0; j < (int)allPath[i].size(); j++) {
			cout << allPath[i][j] << " ";
		}
		cout << endl;
	}
}