#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, row, column;
	int result, size;
	int x = 0, y = 0;

	cin >> n >> row >> column;
	size = pow(2, n);

	result = 0;
	while (size >= 1) {
		size = size / 2;

		if (row >= y + size) {
			result += size * size * 2;
			y += size;
		}

		if (column >= x + size) {
			result += size * size;
			x += size;
		}
	}

	cout << result;
}