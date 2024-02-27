#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int tiling(int n) {
	if (n < dp.size()) {
		return dp[n];
	}
	else {
		dp.push_back((tiling(n - 1) + tiling(n - 2) * 2) % 10007);
		return dp[n];
	}
}

int main() {
	int n;

	dp.push_back(0);
	dp.push_back(1);
	dp.push_back(3);

	cin >> n;

	cout << tiling(n);
}