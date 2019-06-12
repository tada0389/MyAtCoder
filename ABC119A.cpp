#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>

using namespace std;

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

int ABC119Amain() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	string temp;
	temp = s.substr(0, 4);
	if (temp < "2019") {
		cout << "Heisei" << endl;
		return 0;
	}
	temp = s.substr(5, 7);
	cout << temp << endl;
	if (temp < "04") {
		cout << "Heisei" << endl;
		return 0;
	}

	temp = s.substr(8, 10);
	cout << temp << endl;
	if (temp < "30") {
		cout << "Heisei" << endl;
		return 0;
	}
	cout << "TBD" << endl;
	return 0;
}