#include <stdio.h>
#include <iostream>
#include <string.h>

/*
int binary_search(int a[], int value, int left, int right) {
	if (left > right) return 0;
	int mid = (left + right) / 2;
	if (a[mid] == value) return 1;

	if (a[mid] < value) return binary_search(a, value, mid + 1, right);
	else return binary_search(a, value, left, mid - 1);
}

int main() {
	int a[] = { 2, 3, 5, 6, 7, 9, 10, 12, 15, 20,
	21, 27, 28, 29, 39, 41, 42, 44, 46, 48, 50 };

	int num = (sizeof(a)) / (sizeof(a[0]));

	int i;
	for (i = 0; i < 5; i++) {
		int value;
		std::cin >> value;
		if (binary_search(a, value, 0, num - 1)) std::cout << "Found" << std::endl;
		else std::cout << "Not Found" << std::endl;
	}

	return 0;
}*/


/*
char T[] = "wxwvwmwwmwmmwwwwwwwvwnxwmmwxmwmxwvwxwwwwwwwwwwxmmmxvv";
int a[] = { 47,10,24,48,8,28,5,11,25,49,39,21,52,51,3,19,33,9,23,
	7,4,29,20,2,18,32,6,17,16,15,14,13,12,36,37,38,39,40,41,42,
	43,44,45,26,0,34,46,27,50,22,1,31,35 };

int binary_search(char value[], int left, int right) {
	if (left > right) return 0;
	int mid = (left + right) / 2;

	int i;
	int isMatch = 1;
	int isBigger = -1;
	for (i = 0; i < (int)strlen(value); i++) {
		std::cout << T[i + a[mid]];
		if (value[i] > T[i + a[mid]]) {
			isBigger = 1;
			isMatch = 0;
			break;
		}
		else if (value[i] < T[i + a[mid]]) {
			isBigger = 0;
			isMatch = 0;
			break;
		}
	}

	std::cout<< a[mid] << std::endl;
	if (isMatch) return 1;
	if (isBigger) return binary_search(value, mid + 1, right);
	else return binary_search(value, left, mid - 1);
}

int main() {
	int num = (sizeof(a)) / (sizeof(a[0]));

	int i;
	for (i = 0; i < 5; i++) {
		char str[20];
		std::cin >> str;
		if (binary_search(str, 0, num - 1)) std::cout << "Found" << std::endl;
		else std::cout << "Not Found" << std::endl;
	}

	return 0;
}*/