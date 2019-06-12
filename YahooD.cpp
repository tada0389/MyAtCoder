#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int YahooDmain() {
	long long l;
	cin >> l;
	vector<long long>a(l);
	vector<long long>ta(l);
	for(int i = 0; i < l; i++) {
		cin >> a[i];
		ta[i] = a[i];
	}

	int cnt = 0;

	// これですべてのa[i]が0か1になった
	for (int i = 0; i < l; i++) {
		if (a[i]) {
			a[i]--;
		}
		else {
			a[i]++;
		}
		if (a[i] >= 2) {
			a[i] = a[i] % 2;
		}
	}

	/*cout << endl;
	for (int i = 0; i < l; i++) {
		cout << a[i] << endl;
	}*/
	vector<int> sum(l, 0);
	vector<int> tsum(l, 0);

	if (a[0]) sum[0]++;
	if (ta[0]) tsum[0]++;
	for (int i = 1; i < l; i++) {
		if (a[i]) {
			sum[i] = sum[i - 1] + 1;
			//cout << i << " : " << sum[i] << endl;
		}
		else {
			sum[i] = sum[i - 1];
		}
		tsum[i] = tsum[i - 1] + ta[i];
	}
	cnt = sum[l - 1];
	int outSum = 0;
	int outtSum = 0;
	int outI = 0;
	int nowX = 0;
	int firstX = 0;
	//cout << cnt << endl;
	for (int i = 0; i < l; i++) {
		if ((sum[i]-outSum) <= (i+1-outI)/2) {
			cnt -= (i+1 - outI) - (sum[i] - outSum) * 2;
			outSum = sum[i];
			outtSum = tsum[i];
			outI = i+1;
			firstX = i;
		}
		if ((sum[l - 1] - sum[i]) * 2 <= l-i-1) {
			cnt -= (l-i-1 - (sum[l - 1] - sum[i])*2);
			//cout << (sum[i]) * 2 << endl;
			nowX = i;
			break;
		}
	}
	//cout << cnt << endl;
	// ラストスパート　どこで終わるか　どこまで戻るか
	priority_queue<int> pq;
	int tc = 0;
	pq.push(tc);
	int nc = 0;
	for (int j = nowX; j < l; j++) {
		if (a[j]) {
			nc--;
		}
		else {
			nc++;
		}
		tc = 0;
		for (int i = 1; i <= j; i++) {
			if ((j - sum[i]) <= (i + 1) / 2) {
				tc -= (i + 1) - (j - sum[i]) * 2;
			}
			if ((sum[i] - sum[0]) * 2 <= j - 1) {
				tc -= (j - 1 - (sum[i] - sum[0]) * 2);
				break;
			}
			if (a[j - i]) {
				tc++;
			}
			else {
				tc--;
			}
			pq.push(nc+tc);
		}
	}

	cnt -= pq.top();
	cout << cnt << endl;

	return 0;
}