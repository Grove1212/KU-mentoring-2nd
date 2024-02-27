	#include <iostream>

	using namespace std;

	int* v;

	/*
	int calculate(int n) { //메모리 초과
		if (v[n] != 0) {
			return v[n];
		}
		else {
			int min = 1000000;
			int x;

			if (n % 3 == 0) {
				x = calculate(n / 3) + 1;
				if (min > x)
					min = x;
			}

			if (n % 2 == 0) {
				x = calculate(n / 2) + 1;
				if (min > x)
					min = x;
			}

			x = calculate(n - 1) + 1;
			if (min > x)
				min = x;

			v[n] = min;
			return min;
		}
	}
	*/

	int calculate(int n) {
		for (int i = 1; i < n; i++) {
			if (i + 1 <= n) {
				if (v[i + 1] == 0) {
					v[i + 1] = v[i] + 1;
				}
				else if (v[i + 1] > v[i] + 1) {
					v[i + 1] = v[i] + 1;
				}
			}

			if (i * 2 <= n) {
				if (v[i * 2] == 0) {
					v[i * 2] = v[i] + 1;
				}
				else if (v[i * 2] > v[i] + 1) {
					v[i * 2] = v[i] + 1;
				}
			}

			if (i * 3 <= n) {
				if (v[i * 3] == 0) {
					v[i * 3] = v[i] + 1;
				}
				else if (v[i * 3] > v[i] + 1) {
					v[i * 3] = v[i] + 1;
				}
			}
		}

		return v[n];
	}

	int main() {
		int n;

		cin >> n;

		v = new int[n + 1];

		for (int i = 0; i <= n; i++)
			v[i] = 0;

		cout << calculate(n);

		delete[] v;
	}