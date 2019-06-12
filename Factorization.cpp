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
#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()
#define pb push_back

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1 << 60LL;
const ll mod = 1e9 + 7;
// 0~3�܂ł͉E������ 4~7�܂ł͎΂�
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

// �^�ɂ��ϐ��̃I�[�o�[�t���[�ɋC������I�I
// �Y�񂾂�}��O���t�������I�I�Y�ޑO���珑���I�I

// �f�������� pair.first�őf���Apair.second�őΉ�����w��
vector<pair<long long, long long> > prime_factorize(long long n) {
	vector<pair<long long, long long> > res;
	for (long long p = 2; p * p <= n; ++p) {
		if (n % p != 0) continue;
		int num = 0;
		while (n % p == 0) { ++num; n /= p; }
		res.push_back(make_pair(p, num));
	}
	if (n != 1) res.push_back(make_pair(n, 1));
	return res;
}

const int MAX = 210000;

//�񍀌W�������߂�O���� �e�[�u�������@O(n)
// fac�͊K��
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

// �񍀌W���v�Z
ll COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;
	COMinit();

	auto vec = prime_factorize(m);
	long long res = 1;
	for (auto pa : vec) { // �֗�
		int num = pa.second;
		long long temp = COM(num + n - 1, n - 1); // 0����z��̗v�f���n�܂�̂ŁAn-1�Ƃ��Ă���
		res = (res * temp) % mod;
	}

	cout << res << endl;
}*/