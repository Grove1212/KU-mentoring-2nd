#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int N, M, V;
bool visited_DFS[1001] = { false, };
bool visited_BFS[1001] = { false, };
int graph[1001][1001];
queue<int> q;

void dfs(int idx) {
	visited_DFS[idx] = true;
	cout << idx << ' ';

	for (int i = 1; i <= N; i++) {
		if (!visited_DFS[i] && graph[idx][i]) {
			dfs(i);
		}
	}
}

void bfs(int idx) {
	q.push(idx);
	visited_BFS[idx] = true;
	cout << idx << ' ';

	while (!q.empty()) {
		idx = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (visited_BFS[i] == 0 && graph[idx][i] == 1) {
				q.push(i);
				visited_BFS[i] = true;
				cout << i << ' ';
			}				
		}		
	}
}

int main(void) {
	cin >> N >> M >> V;

	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}


