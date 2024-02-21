#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, K;
int map[101][101];
int visited[101][101];
int biggest_food;
int cnt = 0;

int dn[4] = { 0,0,-1,1 };
int dm[4] = { -1,1,0,0 };

//DFS »ç¿ë
void dfs(int n, int m) {
	cnt++;
	visited[n][m] = true;

	for (int i = 0; i < 4; i++) {
		int nn = n + dn[i];
		int nm = m + dm[i];

		if (nn <= 0 || nn > N || nm <= 0 || nm > M) continue;

		if (map[nn][nm] && !visited[nn][nm]) {
			dfs(nn, nm);
		}
	}
}

int main(void) {
	cin >> N >> M >> K;

	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		map[a][b] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				biggest_food = max(biggest_food, cnt);
			}
		}
	}


	cout << biggest_food << '\n';
}



