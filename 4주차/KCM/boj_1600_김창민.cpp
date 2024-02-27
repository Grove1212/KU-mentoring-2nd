#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int width, height;
int horse;
vector<vector<bool>> obstacle;
vector<vector<pair<int, int>>> land;

int BFS() {
	queue<pair<int, int>> loc;
	queue<int> horse_cnt;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int hx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int hy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int tx, ty, x, y, h;
	int size, i, j;
	int cnt = 0;
	int flag = false;

	loc.push({ 0, 0 });
	horse_cnt.push(horse);
	land[0][0].first = 0;
	land[0][0].second = horse;

	if (width == 1 && height == 1)
		return 0;

	while (!loc.empty()) {
		size = loc.size();
		cnt++;

		for (i = 0; i < size; i++) {
			x = loc.front().second;
			y = loc.front().first;
			h = horse_cnt.front();
			loc.pop();
			horse_cnt.pop();

			for (j = 0; j < 4; j++) {
				tx = x + dx[j];
				ty = y + dy[j];

				if (tx >= 0 && tx < width && ty >= 0 && ty < height && !obstacle[ty][tx]) {
					if (tx == width - 1 && ty == height - 1) {
						flag = true;
						break;
					}

					if (land[ty][tx].first == -1 || land[ty][tx].first > cnt || land[ty][tx].second < h) {
						land[ty][tx].first = cnt;
						land[ty][tx].second = h;
						loc.push({ ty, tx });
						horse_cnt.push(h);
					}
				}
			}

			if (h > 0) {
				for (j = 0; j < 8; j++) {
					tx = x + hx[j];
					ty = y + hy[j];

					if (tx >= 0 && tx < width && ty >= 0 && ty < height && !obstacle[ty][tx]) {
						if (tx == width - 1 && ty == height - 1) {
							flag = true;
							break;
						}

						if (land[ty][tx].first == -1 || land[ty][tx].first > cnt || land[ty][tx].second < h - 1) {
							land[ty][tx].first = cnt;
							land[ty][tx].second = h - 1;
							loc.push({ ty, tx });
							horse_cnt.push(h - 1);
						}
					}
				}
			}
		}

		if (flag)
			break;
	}

	if (flag) {
		return cnt;
	}
	else {
		return -1;
	}
}

int main() {
	vector<bool> bv;
	vector<pair<int, int>> iv;
	int i, j;
	bool b;

	cin >> horse;
	cin >> width >> height;

	for (i = 0; i < width; i++) {
		bv.push_back(false);
		iv.push_back({ -1, -1 });
	}

	for (i = 0; i < height; i++) {
		obstacle.push_back(bv);
		land.push_back(iv);
	}

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cin >> b;
			obstacle[i][j] = b;
		}
	}
	
	cout << BFS();
}