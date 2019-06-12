#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int AGC30Bmain() {
	int l, n;
	cin >> l >> n;
	vector<int>x(n);
	vector<int>y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		y[n - i - 1] = l - x[i];
	}

	long int sum = 0;
	int nowX = 0;
	int head = 0;
	int tail = n - 1;
	// �ŏ��̍���肷��񐔂����߂ČJ��Ԃ�
	// �ŏ������
	// �����ƉE�����J��Ԃ�
	while(head != tail){
		// �����
		if (nowX < x[head]) {
			sum += x[head] - nowX;
		}
		else {
			sum += l - nowX + x[head];
		}
		nowX = x[head];
		cout << sum << endl;

		head += 1;

		if (head == tail)
			break;

		// �E���
		if (nowX > x[tail]) {
			sum += nowX - x[tail];
		}
		else {
			sum += nowX + l - x[tail];
		}
		nowX = x[tail];
		cout << sum << endl;

		tail -= 1;
	}

	priority_queue<long int> pq;
	pq.push(sum);

	for (int i = 1; i < n; i++) {
		sum -= 2 * x[i - 1];
		if ((i + n) % 2 == 1) { // ���̏�Ԃ��ƍŌ㍶�����ł����
			sum -= l - x[tail + 1];
			sum += x[tail];
		}
		else {

		}
	}

	nowX = 0;
	head = 0;
	tail = n - 1;

	// �ŏ��E���
	// �E���ƍ������J��Ԃ�
	while(head != tail){
		// �E���
		if (nowX > x[tail]) {
			sum += nowX - x[tail];
		}
		else {
			sum += nowX + l - x[tail];
		}

		nowX = x[tail];
		cout << sum << endl;

		tail -= 1;

		if (head != tail)
			break;

		// �����
		if (nowX < x[head]) {
			sum += x[head] - nowX;
		}
		else {
			sum += l - nowX + x[head];
		}
		nowX = x[head];
		cout << sum << endl;
		head += 1;
	}


	cout << max(sum,sum) << endl;

	return 0;
}