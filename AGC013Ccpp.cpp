#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int AGC013Cmain() {
	int n, l, t;
	cin >> n >> l >> t;
	vector<int>x;
	vector<int>w;
	for (int i = 0; i < n; i++) {
		int tmpX, tmpW;
		cin >> tmpX >> tmpW;
		x.push_back(tmpX);
		w.push_back(tmpW);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (w[i] == 1) cnt -= (t + x[i]) / l;
		else cnt += (t + (l - x[i] - 1)) / l;
	}
	for (int i = 0; i < n; i++) {
		int tempX = x[i];
		if (w[i] == 1)
			tempX += t;
		else

			tempX -= t;
		tempX %= l;
		if (tempX < 0)
			tempX = (tempX + l)%l;
		x[i] = tempX;
	}

	//if(cnt >= 0)
		//cnt %= n;
	//else cnt = -(-cnt % n) + n;
	cnt = (cnt % n + n) % n; // •‰‚Ì”‚É‚à‘Î‰‚µ‚½•Ö—˜‚ÈmodŒvZ
	sort(x.begin(), x.end());

	//cout << cnt << endl;
	// x[cnt] == x[0]‚ª‚à‚Æ‚à‚Æˆê”Ô–Ú‚Ì‹a‚¾‚Á‚½
	vector<int> newPosition(n);
	for (int i = 0; i < n; i++) {
		newPosition[(cnt + i) % n] = x[i];
	}
	for (int i = 0; i < n; i++) {
		cout << newPosition[i] << endl;
	}
	return 0;
}