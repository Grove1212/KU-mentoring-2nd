#include <iostream>
#include <vector>
using namespace std;

int X;

int main() {
	cin >> X;
	vector<int> dp(X + 1);

	dp[1] = 0;
	for (int i = 2; i <= X; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[X] << endl;
	return 0;
}

//Âü°í https://danidani-de.tistory.com/4