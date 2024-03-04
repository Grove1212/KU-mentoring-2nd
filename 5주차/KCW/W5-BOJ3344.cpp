//백트래킹
#include <iostream>
#include <vector>
using namespace std;

int N, cnt;
int x[16];

bool isPossible(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (x[i] == col) return false;
		if (x[i] == col - (row - i)) return false;
		if (x[i] == col + (row - i)) return false;
	}
	return true;
}

void backtrack(int row) {
	if (row == N) {
		cnt++;
	}
	
	for (int col = 0; col < N;col++) {
		if (isPossible(row, col)) {
			x[row] = col;
			backtrack(row+1);
		}
	}	
}

int main() {

	cin >> N;
	backtrack(0);
	cout << cnt << '\n';
	return 0;
}