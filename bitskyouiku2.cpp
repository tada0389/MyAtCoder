#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>

using namespace std;
/*
typedef long long ll;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define allof(a) (a).begin(), (a).end()
#define INF (1<<30)
#define INFLL (1ll << 60)

const ll mod = 1e9 + 1;

// �^�ɂ��ϐ��̃I�[�o�[�t���[�ɋC������I�I

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> x(n);
	vector<ll> y(n);
	vector<ll> z(n);
	rep(i, 0, n) {
		cin >> x[i] >> y[i] >> z[i];
	}

	// ��Βl�̘a���ő�
	// O(n^2)������
	// +��-���܂�8�ʂ���l����
	priority_queue<ll> pq;
	vector<ll> sum(n, 0);
	rep(bit, 0, 1 << 3) { // 000 001 011�̂悤�� 1�Ȃ�+ 0�Ȃ�-
		ll total = 0;
		ll a, b, c;
		rep(i, 0, n) sum[i] = 0;
		rep(i, 0, n) {
			if (bit & (1 << 0)) sum[i] += x[i];
			else sum[i] -= x[i];
			if (bit & (1 << 1)) sum[i] += y[i];
			else sum[i] -= y[i];
			if (bit & (1 << 2)) sum[i] += z[i];
			else sum[i] -= z[i];
		}
		sort(allof(sum), greater<ll>());
		rep(i, 0, m) total += sum[i];
		pq.push(total);
		//cout << total << endl;
	}

	cout << pq.top() << endl;

	return 0;
}*/