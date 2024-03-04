#include <iostream>
using namespace std;

#define n 4
#define r 3

int dcArr[r] = { 0, };

void printArray(int* arr) {
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void combination(int depth, int next) {
	if (depth == r) {
		printArray(dcArr);
		return;
	}

	for (int i = next; i <= n; i++) {
		dcArr[depth] = i;
		combination(depth + 1, i);
	}
}

int main(void) {
	cout << "�ߺ� ���� (���� x, �ߺ� o)" << endl;
	combination(0, 1);

	return 0;
}