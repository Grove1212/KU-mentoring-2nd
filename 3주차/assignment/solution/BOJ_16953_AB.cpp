#include <bits/stdc++.h>

using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // A, B <= 10^9
    // 2 * A <= 2 * 10^9 <-- no overflow
    int A, B;
    cin >> A >> B;

    // 10 곱하는 연산에서 overflow 체크가 귀찮다.. 그냥 long long 사용~
    // { 현재까지의 연산 횟수, 현재 숫자 }
    queue<pair<int,long long>> q;
    q.emplace(0, A);

    function<long long(long long)> fn[2] = {
            [](long long s) { return 2L * s; },
            [](long long s) { return 10L * s + 1; }
    };

    int ans = -2;
    // 2가지 연산으로 사이클이 형성되지 않으므로, visited 체크 불필요
    // but, 불필요한 탐색을 pruning하기 위해서, dist[k] := k에 도달하기 위한 최단 거리를 저장
    // 사실 다익스트라로 접근하는게 적절해보이지만 bfs탐색의 같은 depth에 있는 원소들은 동일한 dist를 가지므로
    // 항상 먼저 방문한 것이 최단거리임을 보일 수 있음
    // dist[k] 대신 visited[k]로 저장한다.
    // 실질적으로 visited내부에 있는 원소들은 sparse하게 분포하고 그 개수가 크지 않으므로 map으로 선언하는 것이 적절하다
    unordered_map<int, bool> visited;

    while (!q.empty()) {
        auto [acDist, cur] = q.front(); q.pop();
        assert(A <= cur && cur <= B);
        if (cur == B) {
            ans = acDist;
            break;
        }
        // 2가지 operation, 시뮬레이션
        for (int i = 0; i < 2; i++) {
            long long nxt = fn[i](cur);
            if (nxt > B || visited[nxt]) continue; // 감소 연산이 없으므로, 해당 경로는 후보해가 아니다.
            visited[nxt] = true;
            q.emplace(acDist + 1, nxt);
        }
    }
    cout << ans + 1;

    return 0;
}
