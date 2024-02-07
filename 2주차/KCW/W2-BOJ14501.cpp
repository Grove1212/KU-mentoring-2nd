#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int answer, N;

void dfs(int day, int income, vector<pair<int, int>> schedule) {
	answer = max(answer, income); // 모든 경우의 수 중에서 max만 남기면 됨
	for (int i = day; i < N; i++) {
		int next_day = i + schedule[i].first;
		if (next_day > N) continue;
		dfs(next_day, income + schedule[i].second, schedule);
	}
}

int main() {
	cin >> N;
	vector<pair<int, int>> schedule(N);
	for (int i = 0; i < N; i++) {
		cin >> schedule[i].first >> schedule[i].second;
		dfs(0, 0, schedule);
		cout << answer << '\n';
	}
}