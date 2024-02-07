#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int graph[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 > nx || nx <= N || 0 > ny || ny >= N)
				continue;

			if (graph[nx][ny] == 0)
				continue;

			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	return graph[N - 1][M - 1];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;

		for (int j = 0; j < M; j++) {
			graph[i][j] = row[j] - '0';
		}
	}

	cout << bfs(0, 0) << '\n';
	return 0;
}
