# 5주차

안녕하세요 :) 오랜만에 뵙는 것 같네요! 프로젝트와 멘토링을 동시에 진행하다보니, 건강을 신경쓰지 못해서 잔병치레를 겪었습니다 🥲 

마지막 주인 만큼 다양한 개념들에 대해서 설명해드리려고 합니다.

### Backtracking

Backtracking은 가능성이 있는 모든 경우를 시도하는 brute-force의 일종입니다. 가능성이 있는 `모든 경우`를 탐색하는 만큼 무조건 최적해를 보장합니다. 하지만, 대부분 $O(2^n)$ 꼴의 복잡도를 가지기 때문에 $n$의 범위를 확인한 후 시도하시는 것을 추천드립니다. 

핵심은 `최적해가 절대 나올 수 없는 탐색을 pruning하는 것` 과 `상태 rollback` 입니다. 

아마, DFS를 제대로 이해하고 있다면 backtracking 또한 쉽게 이해하실 것이라 확신합니다. 대표적인 문제는 `N-Queen` 문제인데요! 시간을 좀 들여서라도 이 문제를 완전하게 정복하시는 것을 추천합니다. 제가 이전부터 강조했던 `상태 공간 트리` 개념을 생각하시면 `rollback` 과 `pruning` 은 쉽게 구현하실 수 있을 겁니다 :)



### Dynamic Programming

Dynamic Programming은 이전에 이미 연산된 결과를 `caching` 하는 것과 메커니즘이 동일합니다. (dp에서는 이를 `memoization`이라고 명명합니다)

이를 위해서는 `상태(state)` 를 잘 정의하는 것이 중요합니다. 그럼, 이 `상태`라는 것은 무엇일까요?

이에 대한 저의 개인적인 정의는 `특정 상황을 표현하는 값` 입니다. (DFA, 유한 오토마타도 참고해보시면 좋을겁니다)

Dynamic Programming이 유용하게 사용될 경우는 cache hit rate가 높을 때와 완전히 동일합니다.



PS에서 다이나믹 프로그래밍은 아래의 경우에 사용합니다.

1. Referential Transparency
	* 항상 동일한 입력에 대해서, 동일한 출력을 내뱉습니다. $f(x_1) = y, f(x_2)= y   \rightarrow x_1 = x_2$ 
2. Optimal Substructure
	* 작은 부분 문제에서 구한 최적해가 큰 문제의 최적해를 구성하는 구조



잘 이해가 안가시죠? :) 

문제를 풀면서 이해를 해보자구요!

결국 DP의 본질은 `탐색` + `메모이제이션` 입니다. 상태를 잘 정의하셨다면, DFS를 이용하여 탐색을 하면서, 이전에 메모이제이션된 결과가 있다면 이를 재활용하는 방식으로, 불필요한 탐색을 제거하는겁니다. 이 방식은 재귀를 사용하여 직관적이고 탐색 순서에 대해서 많은 고민을 하지 않아도 된다는 장점이 있습니다. 하지만, 재귀를 사용하는 만큼 함수호출에 따른 오버헤드는 존재하는 편이구요!  이것을 `Top-Down approach Dynamic Programming` 이라고 합니다.



일반적으로 DP문제의 솔루션을 보면 점화식으로 표현되어 있는 경우가 많을 겁니다. 많은 경험으로 문제의 점화식을 바로 추론할 수도 있겠지만, 이것은 일반적으로 쉽지 않습니다. 하지만 성능 측면에서는 많은 이점이 있고, `base-condition` 과 `recurrence-relation` 만 잘 정의한다면 for기반의 iteration으로 문제를 해결할 수 있습니다. 이것을 `Bottom-up approach Dynamic Programming` 이라고 합니다.



저는 개인적으로 dp문제를 풀 때, 고유한 상태를 정의하고 이 상태들에 대한 전이과정을 신경씁니다. 이는 그래프 탐색의 과정과도 일치합니다. 탐색을 진행하면서 더 큰 문제를 해결할 때, 작은 문제와 큰 문제 사이의 관계를 본다면 점화식이 추론이 되는 경우가 많은데요 (단, 값을 보고 섣부른 일반화는 해선 안됩니다), 이렇게 추론이 가능할 경우 bottom-up으로 접근하고, 그렇지 않는다면 탐색을 진행하면서 memoization을 수행하는 top-down 방식으로 접근하는 편입니다. 

실제로 정답률도 높은 편이구요 👊



### Dijkstra Algorithm

이건 정말 설명을 할 필요가 없을 정도로 BFS와 동일한데요, BFS는 queue를 사용하기 때문에 FIFO 구조를 가집니다. 하지만, 더 중요도가 높은 원소가 먼저 Pop되어야하는 경우가 존재하는데요 대표적인 예가 다익스트라 알고리즘입니다.

$u \rightarrow v$ 로 가는 최단 거리를 고려해보죠. (단, 모든 edge들은 양의 cost를 가집니다)

$u \rightarrow k_1 \rightarrow k_2 \rightarrow .... \rightarrow v$ 의 구조를 생각한다면 $u$ 와 $v$ 사이의 임의의 정점 $k$에 대해서 $(u \rightarrow k) + (k \rightarrow v)$ 로  구분할 수 있을 겁니다. (물론 $k$ 의 집합은 공집합일 수 있습니다) 

*  $u \rightarrow v$ 가 최단 거리가 되기 위해서는 $u \rightarrow k$ 와 $k \rightarrow v$ 가 최단거리가 되어야하는 것은 자명하기 때문에. (둘 다 거리가 양수인 것이 보장됨)

결국 임의의 정점 $k$에 최단 거리로 도달하는 경로로 탐색을 진행해야 $k \rightarrow v$ 로 가는 새로운 탐색이 최적해를 가질 수 있다는 것을 의미합니다. 그래프 탐색에서 가장 치명적인 Cycle을 방지하기 위해 BFS에선 `bool visited[][]` 를 사용했다면 dijkstra에서는 `가능성이 없는 경로 탐색을 제거함과 동시에 사이클을 방지하기 위해` `dist[i] := i번 정점에 도달하기 위한 최단 거리` 꼴로 사용합니다.  그래서 아래와 같은 식으로 pruning과 cycle avoidance를 수행하는 것이죠

```c++
...
    // current -> next 의 가중치가 cost
for (auto [next, cost] : graph[current]) {
    // = 일때는 사이클이 존재하는 것, < 일 때는 해당 경로로 탐색을 진행해도 최적해는 절대 나올 수 없다는 것
	if (dist[next] <= dist[current] + cost) continue; 
}
```





## Assignment(필수)

* [BOJ_1941_소문난칠공주](https://www.acmicpc.net/problem/1941)

* [BOJ_1495_기타리스트](https://www.acmicpc.net/problem/1495)

* LCS 시리즈
* N-Queen 시리즈
* [동적 계획법 시리즈](https://www.acmicpc.net/workbook/view/7319)
* [백트래킹 및 시뮬레이션](https://www.acmicpc.net/workbook/view/7316)

* [다익스트라 시리즈](https://www.acmicpc.net/workbook/view/10433) 



시리즈물은 역량에 맞춰서 풀어보세요 :) 문제 수는 정해두지 않았습니다. 