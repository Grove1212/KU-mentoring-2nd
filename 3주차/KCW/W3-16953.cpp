#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int A, B;

int bfs(int initial, int ans) {
	int cnt = 1;
	queue<pair<int, int>> q;
	vector<int> v;

	q.push({ cnt, initial }); // cnt, cur

	long long mul2, add1, cur;
	while (!q.empty()) {
		cnt = q.front().first;
		cur = q.front().second;
		q.pop();

		if (cur == ans) return cnt;

		mul2 = cur * 2;
		add1 = cur * 10 + 1;
		
		if (mul2 > ans) continue;
		else q.push({ ++cnt, mul2 });
		if (add1 > ans) continue;
		else q.push({ cnt, add1 });
	}
	return -1;
}

int main() {
	cin >> A >> B;

	cout << bfs(A, B);
}