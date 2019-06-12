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
最低でも覚えておきたいSTL
・vector:可変長配列
・set;集合
・map:連想配列
・queue:キュー
・stack:スタック
・priority_queue:優先度付きキュー
*/

// sizeのunion-find
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
		v.push_back(10 * i * 1); //要素の追加
	}
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i] << " "; //各要素の表示
	}
	while (v.size() > 0) {
		v.pop_back(); // 要素の削除
	}
	// 2次元配列の作り方 dp[40][30] すべてに0を代入
	vector<vector<int>> dp;
	dp = vector<vector<int>>(40, vector<int>(30, 0));

	// 三次元配列
	vector<vector<vector<int>>> dp3;
	dp3 = vector<vector<vector<int>>>(10, vector<vector<int>>(20, vector<int>(30, 0)));
	
	set<int> s;
	s.insert(10);
	s.insert(20);
	cout << s.size() << endl;
	// s.count(x); // 要素が含まれているか
	for (Iter iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << endl; // ソート順で列挙　昇順
	}
	s.erase(10);

	typedef map<string, long long> M; // map<key の型, valueの型>
	M m;
	m["Alice"] = 160;
	m["Bob"] = 150;
	m["Alice"] = 200; // m = {"Alice":200, "Bob";150}
	for (M::iterator iter = m.begin(); iter != m.end(); ++iter) {
		// iter->firstはkey iter->secondはvalue
		cout << iter->first << ": " << iter->second << endl;
	}

	int a[5] = { 10, 30, 20, 30 , 40};
	queue<int> q;
	for (int i = 0; i < 4; ++i) q.push(a[i]); // 要素の追加
	while (q.size() > 0) {
		cout << q.front() << endl; // 先頭要素の参照
		q.pop(); // 先頭要素の削除
	}

	stack<int> st;
	for (int i = 0; i < 4; ++i) st.push(a[i]); // 要素の追加
	while(s.size() > 0) {
		cout << st.top() << endl; //　語尾要素の参照
		st.pop(); // 先頭要素の削除
	}

	priority_queue<int> pq;
	for (int i = 0; i < 5; ++i) pq.push(a[i]); // 要素の追加
	while (pq.size() > 0) {
		cout << pq.top() << endl; // 最大要素の参照
		pq.pop(); // 最大要素の削除
	}
	// 以下最小の要素から取り出しにするように変更
	priority_queue<int, vector<int>, greater<int>> pq2;

	for (int i = 0; i < 5; ++i) pq2.push(a[i]);
	while (pq2.size() > 0) {
		cout << pq2.top() << endl;
		pq2.pop();
	}

	// pair(コスト、本体データ)が便利
	pair<double, string> pa(3.14, "pi");
	pa.first = 3;
	cout << pa.first << ", " << pa.second << endl; // 3, pi

	// pairを使うとソートしたい配列の各要素が持っているものも追従して変更できる
	vector<pair<int, int>>pairs(100);
	sort(pairs.begin(), pairs.end());
}
