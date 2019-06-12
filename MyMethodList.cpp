#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

/* STL
Standard Templete Library 
�Œ�ł��o���Ă�������STL
�Evector:�ϒ��z��
�Eset;�W��
�Emap:�A�z�z��
�Equeue:�L���[
�Estack:�X�^�b�N
�Epriority_queue:�D��x�t���L���[
*/

// size��union-find
/*
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};*/

void stl() {
	typedef set<int>::iterator Iter;

	vector<int> v;
	
	for (int i = 0; i < 3; i++) {
		v.push_back(10 * i * 1); //�v�f�̒ǉ�
	}
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " "; //�e�v�f�̕\��
	}
	while (v.size() > 0) {
		v.pop_back(); // �v�f�̍폜
	}
	// 2�����z��̍��� dp[40][30] ���ׂĂ�0����
	vector<vector<int>> dp;
	dp = vector<vector<int>>(40, vector<int>(30, 0));

	// �O�����z��
	vector<vector<vector<int>>> dp3;
	dp3 = vector<vector<vector<int>>>(10, vector<vector<int>>(20, vector<int>(30, 0)));
	
	set<int> s;
	s.insert(10);
	s.insert(20);
	cout << s.size() << endl;
	// s.count(x); // �v�f���܂܂�Ă��邩
	for (Iter iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << endl; // �\�[�g���ŗ񋓁@����
	}
	s.erase(10);

	typedef map<string, long long> M; // map<key �̌^, value�̌^>
	M m;
	m["Alice"] = 160;
	m["Bob"] = 150;
	m["Alice"] = 200; // m = {"Alice":200, "Bob";150}
	for (M::iterator iter = m.begin(); iter != m.end(); ++iter) {
		// iter->first��key iter->second��value
		cout << iter->first << ": " << iter->second << endl;
	}

	int a[5] = { 10, 30, 20, 30 , 40};
	queue<int> q;
	for (int i = 0; i < 4; ++i) q.push(a[i]); // �v�f�̒ǉ�
	while (q.size() > 0) {
		cout << q.front() << endl; // �擪�v�f�̎Q��
		q.pop(); // �擪�v�f�̍폜
	}

	stack<int> st;
	for (int i = 0; i < 4; ++i) st.push(a[i]); // �v�f�̒ǉ�
	while(s.size() > 0) {
		cout << st.top() << endl; //�@����v�f�̎Q��
		st.pop(); // �擪�v�f�̍폜
	}

	priority_queue<int> pq;
	for (int i = 0; i < 5; ++i) pq.push(a[i]); // �v�f�̒ǉ�
	while (pq.size() > 0) {
		cout << pq.top() << endl; // �ő�v�f�̎Q��
		pq.pop(); // �ő�v�f�̍폜
	}
	// �ȉ��ŏ��̗v�f������o���ɂ���悤�ɕύX
	priority_queue<int, vector<int>, greater<int>> pq2;

	for (int i = 0; i < 5; ++i) pq2.push(a[i]);
	while (pq2.size() > 0) {
		cout << pq2.top() << endl;
		pq2.pop();
	}

	// pair(�R�X�g�A�{�̃f�[�^)���֗�
	pair<double, string> pa(3.14, "pi");
	pa.first = 3;
	cout << pa.first << ", " << pa.second << endl; // 3, pi

	// pair���g���ƃ\�[�g�������z��̊e�v�f�������Ă�����̂��Ǐ]���ĕύX�ł���
	vector<pair<int, int>>pairs(100);
	sort(pairs.begin(), pairs.end());
}
