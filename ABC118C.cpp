#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;

/*long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}*/

int ABC118Cmain() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int temp = a[0];

	for (int i = 1; i < n ; i++) {
		//temp = gcd(a[i], temp);
	}

	cout << temp << endl;
	return 0;
}