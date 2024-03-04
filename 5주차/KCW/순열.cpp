#include <iostream>
using namespace std;

#define n 4
#define r 3

int pArr[r] = { 0, };
bool check[n + 1] = { false, };

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
		if (!check[i]) {
			check[i] = true;
			pArr[depth] = i;
			permutation(depth + 1);
			check[i] = false;
		}
	}
}

int main(void) {
	cout << "순열 (순서 o, 중복 x)" << endl;
	permutation(0);

	return 0;
}