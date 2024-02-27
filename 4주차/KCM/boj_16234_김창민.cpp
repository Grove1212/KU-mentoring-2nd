#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

vector<vector<int>> A;
vector<vector<int>> A_ch;
int mn, mx, n;

bool BFS(int y, int x, int d) {
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int sum = A[y][x];
	A_ch[y][x] = d;
	int i, j, tx, ty;
	int dif;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push({ y, x });
	v.push_back({ y, x });
	int it;

	while (!q.empty()) {
		it = q.size();

		for (j = 0; j < it; j++) {
			y = q.front().first;
			x = q.front().second;
			q.pop();

			for (i = 0; i < 4; i++) {
				tx = x + dx[i];
				ty = y + dy[i];

				if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
					if (A_ch[ty][tx] < d) {
						dif = abs(A[y][x] - A[ty][tx]);
						if (dif >= mn && dif <= mx) {
							q.push({ ty, tx });
							v.push_back({ ty, tx });
							sum += A[ty][tx];
							A_ch[ty][tx] = d;
						}
					}
				}
			}
		}
	}

	if (v.size() > 1) {
		sum = sum / v.size();
		for (i = 0; i < v.size(); i++)
			A[v[i].first][v[i].second] = sum;

		return true;
	}
	else {
		return false;
	}
}

int move() {
	int day = 0;
	bool flag;
	int i, j;

	while (true) {

		flag = false;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (A_ch[i][j] < day)
					if (BFS(i, j, day))
						flag = true;
			}
		}

		if (!flag)
			break;

		day++;
	}

	return day;
}

int main() {
	int t;
	vector<int> v;

	cin >> n >> mn >> mx;

	for (int i = 0; i < n; i++)
		v.push_back(-1);
	for (int i = 0; i < n; i++)
		A_ch.push_back(v);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		A.push_back(v);
	}

	cout << move();
}