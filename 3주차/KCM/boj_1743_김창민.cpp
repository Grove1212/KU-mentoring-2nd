#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;
vector<vector<bool>> aisle;
queue<pair<int, int>> q;

int BFS(int y, int x) {
	if (!aisle[y][x])
		return 0;

	aisle[y][x] = false;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int nx, ny;
	int size = 1;

	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
			if (aisle[ny][nx]) {
				size += BFS(y + dy[i], x + dx[i]);
			}
		}
	}

	return size;
}

int find_max() {
	int max = 0;
	int size;

	while (!q.empty()) {
		size = BFS(q.front().first, q.front().second);

		if (max < size)
			max = size;

		q.pop();
	}

	return max;
}

int main() {
	int n;
	int x, y;
	int i, j;
	vector<bool> v;

	cin >> r >> c >> n;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			v.push_back(false);
		aisle.push_back(v);
		v.clear();
	}

	for (i = 0; i < n; i++) {
		cin >> y >> x;

		q.push({ y - 1, x - 1 });
		aisle[y - 1][x - 1] = true;
	}

	cout << find_max();
}