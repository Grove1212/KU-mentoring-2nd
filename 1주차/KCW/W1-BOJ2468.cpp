#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

int N;
int input[101][101];
int map[101][101];
int visited[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;
vector<int> v;
int cnt;

void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				continue;
			}
			if (map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}

		}
	}
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	cnt = 0;
}

int main() {
	cin >> N;
	int maxHeight = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
			if (input[i][j] > maxHeight)
				maxHeight = input[i][j];
		}
	}

	for (int h = 1; h <= maxHeight; h++) {

		// h 미만 0, h 이상 1
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (input[i][j] < h) {
					map[i][j] = 0;
				}
				else {
					map[i][j] = 1;
				}
			}
		}

		//bfs 영역 개수 구하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);

		reset();
	}
	
	sort(v.begin(), v.end());
	cout << v[v.size() - 1];	
}