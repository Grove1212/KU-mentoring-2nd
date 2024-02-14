#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> maze;
queue<pair<int, int>> jihun;
queue<pair<int, int>> fire;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int r, c;

void fire_spread() {
	int tx, ty;
	int x, y;
	int	n = fire.size();
	int i, j;
	
	for (i = 0; i < n; i++) {
		x = fire.front().first;
		y = fire.front().second;
		
		for (j = 0; j < 4; j++) {
			tx = x + dx[j];
			ty = y + dy[j];

			if (tx >= 0 && tx < c && ty >= 0 && ty < r) {
				if (maze[ty][tx] != '#' && maze[ty][tx] != 'F') {
					fire.push({ tx, ty });
					maze[ty][tx] = 'F';
				}
			}
		}

		fire.pop();
	}
}

bool jihun_move() {
	int tx, ty;
	int x, y;
	int	n = jihun.size();
	int i, j;

	for (i = 0; i < n; i++) {
		x = jihun.front().first;
		y = jihun.front().second;

		for (j = 0; j < 4; j++) {
			tx = x + dx[j];
			ty = y + dy[j];

			if (tx >= 0 && tx < c && ty >= 0 && ty < r) {
				if (maze[ty][tx] == '.') {
					jihun.push({ tx, ty });
					maze[ty][tx] = 'J';
				}
			}
			else {
				return true;
			}
		}

		jihun.pop();
	}

	return false;
}
/*
void print() {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			cout << maze[i][j] << ' ';
		cout << "\n";
	}
	cout << "\n";
}
*/
int escape_time() {
	int time = 0;
	int flag = false;

	//print();
	while (!jihun.empty()) {
		time++;

		fire_spread();
		if (jihun_move()) {
			flag = true;
			//print();
			break;
		}
		//print();
	}

	if (flag) {
		return time;
	}
	else {
		return -1;
	}
}

int main() {
	int i, j;
	int t;
	string s;
	vector<char> v;

	cin >> r >> c;

	for (i = 0; i < r; i++) {
		cin >> s;

		for (j = 0; j < c; j++) {
			v.push_back(s[j]);

			if (s[j] == 'J')
				jihun.push({ j, i });

			if (s[j] == 'F')
				fire.push({ j, i });
		}
		maze.push_back(v);
		v.clear();
	}

	maze.shrink_to_fit();

	t = escape_time();
	if (t == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << t;
	}
}