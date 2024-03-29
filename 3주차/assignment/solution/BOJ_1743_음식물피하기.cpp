#include <bits/stdc++.h>

using namespace std;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<char>> board(N, vector<char>(M));
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        board[--r][--c] = '#';
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != '#')
                continue;
            // BFS
            // {y, x}
            int total = 1;
            queue<pair<int,int>> q;
            board[i][j] = '.';
            q.emplace(i, j);

            while (!q.empty()) {
                auto [y, x] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int ny = y + dir[d][0], nx = x + dir[d][1];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M || board[ny][nx] != '#')
                        continue;
                    // 이 경우는 board[ny][nx] = '#' 라는 것이 보장됨
                    board[ny][nx] = '.';
                    total++;
                    q.emplace(ny, nx);
                }
            }
            ans = max(ans, total);
        }
    }
    cout << ans;
    return 0;
}
