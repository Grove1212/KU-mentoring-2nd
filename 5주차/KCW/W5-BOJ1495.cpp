#include <iostream>

#define endl "\n"
#define MAX 110
using namespace std;

int N, S, M;
int Volume[MAX];
bool DP[MAX][1010];

void Input() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) cin >> Volume[i];
}

void dynamicPrograming() {
	if (S + Volume[1] <= M) DP[1][S + Volume[1]] = true;
	if (S - Volume[1] >= 0) DP[1][S - Volume[1]] = true;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (DP[i-1][j] == true) {//ÀÌÀü °îÀÇ º¼·ýÀÌ¶ó¸é
				if (j + Volume[i] <= M) DP[i][j + Volume[i]] = true;
				if (j - Volume[i] >= 0) DP[i][j - Volume[i]] = true;
			}
		}
	}
	for (int i = M; i >= 0; i--) {
		if (DP[N][i] == true) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

void Solve() {
	Input();
	dynamicPrograming();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}