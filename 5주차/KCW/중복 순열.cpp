#include <iostream>
using namespace std;

#define n 4
#define r 3

int pArr[r] = { 0, };

void printArray(int* arr) {
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void permutation(int depth) {
	if (depth == r) {
		printArray(pArr);
		return;
	}

	for (int i = 1; i <= n; i++) {
		pArr[depth] = i;
		permutation(depth + 1);
	}
}

int main(void) {
	cout << "중복 순열 (순서 o, 중복 o)" << endl;
	permutation(0);

	return 0;
}