#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int MAP[5][5];
bool Select[25] = { 0, };
int Answer;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1,1,0,0 };

void Input() {
	for (int i = 0; i < 5; i++) {
		string Inp;
		cin >> Inp;
		for (int j = 0; j < 5; j++) {
			if (Inp[j] == 'Y') MAP[i][j] = 1;
			else if (Inp[j] == 'S') MAP[i][j] = 2;
		}
	}
}

bool UpFour() {
	int Som = 0;
	for (int i = 0; i < 25; i++) {
		if (Select[i] == true) {
			int x = i / 5;
			int y = i % 5;
			if (MAP[x][y] == 2) Som++;
		}
	}
	if (Som >= 4) return true;
	else return false;
}

bool Adjacency() {
	queue<pair<int, int>> q;
	bool selected[5][5];
	bool visited[5][5];
	bool Check_Answer = false;

	memset(selected, false, sizeof(selected));
	memset(visited, false, sizeof(visited));

	int isFirst = true;
	for (int i = 0; i < 25; i++) {
		if (Select[i] == true) {
			int x = i / 5;
			int y = i % 5;
			selected[x][y] = true;

			if (isFirst == true) {
				q.push({ x,y });
				visited[x][y] = true;
				isFirst = false;
			}
		}
	}// 초기 세팅, 내가 선택한 애들을 표시 및 첫번째 표시

	int adj = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (adj == 7) {
			Check_Answer = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
				if (selected[nx][ny] && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
					adj++;
				}
			}
		}
	}
	return Check_Answer;
}


void combination(int depth, int next) {
	if (depth == 7) {
		if (UpFour() && Adjacency()) Answer++;
		return;
	}

	for (int i = next; i < 25; i++) {
		if (Select[i] == true) continue;
		Select[i] = true;
		combination(depth + 1, i);
		Select[i] = false;
	}
}

void Solution() {
	combination(0, 0);
	cout << Answer << endl;
}

void Solve() {
	Input();
	Solution();
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}