#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
/*
// change minimum a���b�̖@��������������Aa�̒l��b�̒l�ɒu��������
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}

	return false;
}

// change maximum minimum�̋t
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

// ��ʓI�ȗ���
/*
1.DP�z��S�̂��uDP�̎�ނɉ����������l�v�ŏ�����
2.�������������
3.���[�v����
4.�e�[�u��������𓾂ďo��
*/
/*
// k�ȓ���s�����邩�ǂ���
int one() {
	// �v�Z�ʂ��傫������@����
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;

	// ii �Ԗڂ܂ł̐����̒����� kk �̐�����I��ő��������a�� jj �Ƃ��邱�Ƃ��\���ǂ���
	vector<vector<int>> dp;
	dp = vector<vector<int>>(n + 1, vector<int>(s + 1, -1));

	// dp[i][j] i�Ԗڂ܂ł̂������������������Ƃ��̑��aj�ɂł��邩
	// dp[i][j-a[i]]��true�Ȃ�dp[i+1][j]��true
	// dp[i][j]��true�Ȃ�dp[i+1][j]��true

	dp[0][0] = 0;
	int cnt = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i + 1][j] =  dp[i][j];
			if (j - a[i] >= 0) {
				chmin(dp[i + 1][j], dp[i][j - a[i]] + 1);
			}
		}

	}
	
	if (dp[n][s] == -1) cout << "NO" << endl;
	else {
		if (dp[n][s] <= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	// DP�̓Y���ł͂Ȃ��ADP�̒l���̂��̂ɏ������������Ȃ���
// ��ʂ�bool�l�����߂�DP�����邱�Ƃ͖��ʂ������A�����v�Z�ʂł����Ƒ����̂��Ƃ�m�邱�Ƃ��ł���
	// ��̓I�ɂ�dp[n][A] <= K �Ȃ� "YES"
	// dp[n][A] > K �Ȃ� "NO" �Ƃ����悤��
}

// �������Ȃ��i�b�v�T�b�N���
int two() {
	int n;
	int k;
	int w;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;

	// d[i+1][j]:i�Ԗڂ܂ł̕i������傳�̑��a��j�ȉ��ƂȂ�悤�ɑI�񂾂Ƃ��́A���l�̑��a�̍ő�l
	vector<vector<int>> dp;
	dp = vector<vector<int>>(n + 1, vector<int>(s + 1, -1));

	// �v�Z�ʔ��[�Ȃ��Ȃ����Ⴄ����...�Ă��ƂŏC��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) {
			for (int k = 0; k * a[i] <= j; k++){
				chmax(dp[i + 1][j], dp[i][j - k * a[i]] + k * 30);
			}
		}
	}
	// �ȉ��{���@�����̂���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) {
			if (j < a[i]) {
				dp[i + 1][j] = dp[i][j];
			}
			else {
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - a[i]] + v[i]);
			}
		}
	}

	cout << dp[n][w] << endl;
}

// �������t���i�b�v�T�b�N���
void three() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> m(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> m[i];
	}
	// dp[i][j]:=i�Ԗڂ܂ł�j�����ۂɗ]��ő��i�Ԗڂ̌�(���Ȃ��Ƃ���-1)
	vector<vector<int>>dp;
	dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));

	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			
		}
	}
}

//ARC057B
int arc057bin() {
	int n, k;
	cin >> n >> k;
	vector<long long>a(n);
	vector<long long> sum(n + 1,0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	// dp[i][j]:=i���ڂ܂ł�j��@�����ǂ������Ƃ��̏����񐔂̍ŏ��l
	vector<vector<long long>> dp;
	dp = vector<vector<long long>>(n + 1, vector<long long>((n + 1), 10000000000));
	dp[0][0] = 0;

	if (sum[n] == k) {
		cout << 1 << endl;
		return 0;
	}
	/* ������Ƃ��͓O��I�ɕ�����@0syou
	   ���Ƃ��͂��肬��@�����悭����悤��
	// �Q����
	dp[i + 1][j] = dp[i][j]
	dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i][j] + (dp[i][j]+a[i+1])/s + 1 * p�͂��̓��̏�����
	���� dp[i][j]/s < dp[i][j]+p/s+a[i+1]�̂Ƃ��ɂ悭�Ȃ�
	= p > (dp[i][j]+a[i+1])/s�̂Ƃ� 
	*/
/*
	// i���܂ł̏��� > i-1���܂ł̏����̂Ƃ��@���ǂ�����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			// �����Ȃ�
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			// ����
			if (i == 0) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
			else {
				long long atleast = dp[i][j] * sum[i + 1] / sum[i] + 1;
				if (atleast <= a[i] + dp[i][j])
					dp[i + 1][j + 1] = min(dp[i][j + 1],atleast);
			}
		}
	}

	long long ans = 0;

	for (int j = n; j >= 0; j--) {
		if (dp[n][j] <= k) {
			ans = j;
			cout << ans << endl;
			return 0;
		}
	}

	//cout << ans << endl;
}

// �Œ����ʕ�������
void four() {

}


void dfs(const vector<vector<int>> dp, const vector<pair<int, int>> item, int price, int i, vector<int> &selected) {
	if (i == 0 && price == 0) return;
	if (i < 0) return;
	for (int j = i - 1; j >= 0; j--) {
		if (price - item[j].first < 0) continue;
		if (dp[i][price] == dp[i][price - item[j].first] + item[j].second) {
			selected[j] = 1;
			dfs(dp, item, price - item[j].first, j, selected);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> item(n);
	rep(i, n) {
		cin >> item[i].first >> item[i].second;
	}


	// dp[i][j] := i�Ԗڂ܂ł̉ו��������Ƃ��́A�l�i��j�ƂȂ�J�����[
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	rep(i, n) {
		rep(j, k + 1) {
			if (j + item[i].first <= k) {
				dp[i + 1][j + item[i].first] = max(dp[i][j + item[i].first], dp[i][j] + item[i].second);
			}
			else
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}

	//cout << dp[n][k] << endl;
	int ans = dp[n][k];

	vector<int> selected(n, 0);

	//dfs(dp, item, k, n, selected);

	cout << ans << endl;
	rep(i, n) {
		cout << selected[i] << " ";
	}
	cout << endl;

	return 0;
}
*/