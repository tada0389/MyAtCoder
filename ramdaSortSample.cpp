#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <list>
#include <numeric>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3�܂ł͉E������ 4~7�܂ł͎΂�
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// �ő����
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// �ŏ����{��
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

/*
//
// �����_���̊w�K�p�T���v��
//
// �Q�lURLs
//   http://www.cprogramming.com/c++11/c++11-lambda-closures.html
//   http://wwweic.eri.u-tokyo.ac.jp/computer/manual/altixuv/doc/Compiler/CC/jp_lnx_cppdocs11.1.tar/Documentation/ja_JP/compiler_c/main_cls/cref_cls/common/cppref_lambda_lambdacapt.htm
//   http://handasse.blogspot.com/2010/01/c0x-stl.html
//   http://kaworu.jpn.org/cpp/%E3%83%A9%E3%83%A0%E3%83%80%E5%BC%8F


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void basic() {
	// ��������Ƃ�A���̓���Ԃ������_�֐����`
	auto f1 = [](int x) { return x * x; };

	// �����_�֐����Ăяo���B�֐��|�C���^�݂����Ɏg����
	std::cout << "1: " << f1(1) << std::endl;
	std::cout << "3: " << f1(3) << std::endl;
	std::cout << "5: " << f1(5) << std::endl;
	// ��������Ƃ�A���̓���Ԃ������_�����`

	// �������Ƃ�A���̘a��Ԃ������_�֐����`
	auto f2 = [](int x, int y) { return x + y; };
	// �����_�֐����Ăяo��
	std::cout << "1 + 4: " << f2(1, 4) << std::endl;
	std::cout << "8 + 9: " << f2(8, 9) << std::endl;

	// �߂�l�̌^�𖾎����Ă��悢
	auto f1_double = [](int x) -> double { return x * x; };
	std::cout << "10000: " << f1_double(10000) << std::endl;

	// �������Ƃ�Ȃ��ꍇ()�͏ȗ��ł���
	// �������ȗ����Ȃ��������₷�������H
	auto f_abbrv = [] { std::cout << "hello!" << std::endl; };
	f_abbrv();
}

// capture�̗�
void capture() {
	int a = 3;
	int b = 7;

	// error! �O���Œ�`���ꂽ�ϐ��͂��̂܂܂ł͎g���Ȃ�
	// auto f_offset = [](int n){ return a * n + b; };

	// []�̒��ɁA�R�s�[�������ϐ��𗅗񂷂�ƁA���̕ϐ������[�h�I�����[�Ō�����
	auto f_offset = [a, b](int n) { return a * n + b; };
	std::cout << "a * 5 + b = " << f_offset(5) << std::endl;

	// []�̒���=�Ə����ƁA���ׂĂ̊O���̕ϐ������[�h�I�����[�Ō�����
	auto f_offset2 = [=](int n) { return a * n + b; };
	std::cout << "a * 5 + b = " << f_offset2(5) << std::endl;

	// []�̒���&�Ə����ƁA���ׂĂ̊O���̕ϐ������������\��ԂŌ�����
	auto f_offset3 = [&](int n) { a = 100; b = 77; return a * n + b; };
	std::cout << "a * 5 + b = " << f_offset3(5) << std::endl;
}

// ���ёւ��̗�
void applicationSort() {
	struct data_t {
		int num;
		std::string str;
	};

	std::vector<data_t> data_array(3);

	data_array[0].num = 15;
	data_array[0].str = "zzz";
	data_array[1].num = 30;
	data_array[1].str = "aaa";
	data_array[2].num = 15;
	data_array[2].str = "ccc";

	// ���ёւ��̕��@�������_�֐��ŋL�q
	sort(data_array.begin(),
		data_array.end(),
		[](const data_t& a, const data_t& b) {return (a.num == b.num) ? (a.str < b.str) : (a.num < b.num); }
	);

	// ���ʂ��m�F
	for (int i = 0; i < (int)data_array.size(); ++i) {
		std::cout << "i " << i << ": " << std::endl;
		std::cout << "  num: " << data_array[i].num << std::endl;
		std::cout << "  str: " << data_array[i].str << std::endl;
	}
}

// foreach�̗�
void applicationForEach() {
	std::vector<int> vec{ 2, 3, 5, 7, 11 };

	// before
	for (auto n : vec)
	{
		std::cout << n << ", ";
	}
	std::cout << std::endl;

	// &���g�����ƂŒl�����������\
	std::for_each(vec.begin(), vec.end(), [](int &n) { n = n * n; });

	// after
	for (auto n : vec)
	{
		std::cout << n << ", ";
	}
	std::cout << std::endl;
}

int main() {
	basic();
	capture();
	applicationSort();
	applicationForEach();
	return 0;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> a(n);
	rep(i, n) cin >> s[i] >> a[i];

	vector<int> ord(n);
	iota(allof(ord), 0);
	sort(allof(ord), [&](int x, int y) {
		if (s[x] == s[y]) return a[x] > a[y];
		return s[x] < s[y];
	});
	rep(i, n) {
		cout << ord[i] + 1 << endl;
	}

	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> p(n);
	rep(i, n) cin >> s[i] >> p[i];
	vector<int> ord(n);

	iota(allof(ord), 0);

	sort(allof(ord), [&](int x, int y) {
		if (s[x] == s[y]) return p[x] > p[y];
		return s[x] < s[y];
	});

	rep(i, n) {
		cout << ord[i] + 1 << endl;
	}
	return 0;
}
*/