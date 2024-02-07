#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int sx, sy;
queue<pair<int, int>> q;
vector<vector<int>> maze;

void BFS(int x, int y) {
	q.pop();
	
	int tx, ty;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	for (int i = 0; i < 4; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < sx && ty >= 0 && ty < sy) {
			if (maze[ty][tx] == 1 && (ty != 0 || tx != 0)) {
				maze[ty][tx] = maze[y][x] + 1;
				q.push(make_pair(tx, ty));
			}
			else if (maze[ty][tx] > 1) {
				if (maze[ty][tx] > maze[y][x] + 1) {
					maze[ty][tx] = maze[y][x] + 1;
					q.push(make_pair(tx, ty));
				}
			}
		}
	}

	if (!q.empty())
		BFS(q.front().first, q.front().second);
}

int main() {
	string s;
	int i, j;
	vector<int> v;

	cin >> sy >> sx;

	for (i = 0; i < sy; i++) {
		cin >> s;

		for (j = 0; j < sx; j++) {
			v.push_back(s[j] - '0');
		}
		maze.push_back(v);
		v.clear();
	}

	q.push(make_pair(0, 0));
	BFS(0, 0);

	cout << maze[sy - 1][sx - 1] << "\n";

	/*
	for (i = 0; i < sy; i++) {
		for (j = 0; j < sx; j++) {
			cout << maze[i][j] << ' ';
		}
		cout << "\n";
	}
	*/
}