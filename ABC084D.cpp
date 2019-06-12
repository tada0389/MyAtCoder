#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <math.h>

#define MAX 10e5

using namespace std;
/*
bool IsPrime(int num) {
	if (num < 2) return false;
	else if (num == 2)return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int ABC084Dmain() {
	int q;
	cin >> q;
	vector<int> l;
	vector<int> r;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		l.push_back(a);
		r.push_back(b);
	}

	vector<int> sum(MAX,0);
	vector<int> isPrime(MAX,0);

	for (int i = 3; i < MAX; i += 2) {
		if (IsPrime(i))
			isPrime[i] = 1;
	}

	for (int i = 2; i < MAX / 2; i++) {
		if (isPrime[2 * i - 1] != 1)
			continue;
		if (IsPrime(i)) {
			//cout << 2 * i - 1 << "‚Í‘f”" << endl;
			continue;
		}
		else {
			isPrime[2 * i - 1] = 0;
		}
	}

	sum[3] = 1;

	for (int i = 5; i < MAX; i += 2) {
		sum[i] = sum[i - 2] + isPrime[i];
	}

	for (int i = 0; i < q; i++) {
		int x = sum[r[i]] - sum[l[i]];
		if (isPrime[l[i]])
			x += 1;
		cout << x << endl;
		//cout << r[i] << " " << sum[r[i]] << endl << l[i] << " " << sum[l[i]] << endl;
	}

	for (int i = 0; i < q; i++) {
		//cout << sum[i] << endl;
	}
	return 0;

}*/