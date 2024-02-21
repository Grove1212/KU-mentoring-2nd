#include <iostream>
#include <vector>

using namespace std;

int cleaned = 0;
//int px, py;
vector<vector<bool>> room;
vector<vector<bool>> is_cleaned;

bool check(int y, int x) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	int tx, ty;
	bool flag = false;

	for (int i = 0; i < 4; i++) {
		tx = x + dx[i];
		ty = y + dy[i];

		if (!is_cleaned[ty][tx]) {
			flag = true;
			break;
		}
	}

	return flag;
}
/*
void print(int r, int c) {
	int i, j;

	cout << "\n";
	for (i = 0; i < py; i++) {
		for (j = 0; j < px; j++) {
			if (i != r || j != c) {
				cout << room[i][j] << ' ';
			}
			else {
				cout << "r ";
			}
		}
		cout << "\t";
		
		for (j = 0; j < px; j++)
			cout << is_cleaned[i][j] << ' ';
		cout << "\n";
	}
	cout << "\n";
}
*/
void clean(int r, int c, int d) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	int tx, ty;

	//print(r, c);
	while (true) {
		if (!is_cleaned[r][c]) {
			is_cleaned[r][c] = true;
			cleaned++;
		}

		//print(r, c);

		if (!check(r, c)) {
			tx = c + dx[(d + 2) % 4];
			ty = r + dy[(d + 2) % 4];
			if (!room[ty][tx]) {
				r = ty;
				c = tx;
			}
			else {
				break;
			}
		}
		else {
			d = (d + 3) % 4;
			tx = c + dx[d];
			ty = r + dy[d];

			if (!is_cleaned[ty][tx]) {
				c = tx;
				r = ty;
			}
		}
	}
}

int main() {
	int n, m;
	int r, c, d;
	int i, j;
	vector<bool> v;
	bool b;

	cin >> n >> m;
	cin >> r >> c >> d;
	//px = m;
	//py = n;

	for (i = 0; i < m; i++)
		v.push_back(false);
	for (i = 0; i < n; i++)
		is_cleaned.push_back(v);
	v.clear();

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> b;
			v.push_back(b);

			if (b)
				is_cleaned[i][j] = true;
		}
		room.push_back(v);
		v.clear();
	}
	
	clean(r, c, d);

	cout << cleaned;
}