# Breadth First Search (BFS)

BFS는 시작점에서 탐색을 시작하여 그래프를 계층적으로 탐색하는 알고리즘으로 DFS와 함께 그래프 탐색에서 가장 일반적으로 사용되는 탐색 알고리즘이다. 계층적으로 탐색하기 위해 특정 노드를 방문했을 때 인접한 노드 중 방문하지 않은 노드들을 모두 Queue에 넣어준다.

## 중복 탐색을 방지하기 위한 bool 배열의 필요성

양방향 그래프(혹은 단방향 그래프에서 사이클이 존재하는 경우)에서 BFS를 사용시 노드의 중복 탐색이 발생한다. 때문에 방문한 노드의 기록을 남겨놓는 bool 배열을 만들어서 방문하지 않은 경우에 Queue에 넣음과 동시에 방문 처리(`visited[node] = true`)를 해준다.

## 사용

- 특정 노드까지의 최단 거리를 구하는 경우(모든 간선의 가중치가 1인 경우 가능)

- 최단 경로 구하는 경우

- 모든 node를 한 번씩 방문하는 경우

- `Dijkstra Algorithm`

- `Prim Algorithm`

## 설명

![BFS](https://user-images.githubusercontent.com/50372451/116848799-58000e00-ac28-11eb-8ba2-00394805d499.gif)

<details>
<summary>예시 설명 (클릭)</summary>
<p>

> 각각의 노드와 연결된 다른 노드의 번호는 오름차순대로 삽입되어 있다고 가정
>
> `0`번 노드에서 시작

1. `0`번 노드 방문

   1. `0`번 노드와 인접한 노드(`1`, `2`, `3`)를 Queue에 넣는다.

   2. `0`번 노드 탐색 종료

2. `1`번 노드 방문

   1. `1`번 노드와 인접한 노드(`4`)를 Queue에 넣는다.

      - `0`번 노드는 이미 방문 했으므로 생략

   2. `1`번 노드 탐색 종료

3. `2`번 노드 방문

   1. `2`번 노드와 인접한 노드들(`5`)을 Queue에 넣는다.

      - `0`번, `4`번 노드는 이미 방문 했으므로 생략

   2. `2`번 노드 탐색 종료

4. `3`번 노드 방문

   1. `3`번 노드와 인접한 노드들을 다 방문했기 때문에 Queue에 아무것도 넣지 않는다.

      - `0`번 노드는 이미 방문 했으므로 생략

   2. `3`번 노드 탐색 종료

5. `4`번 노드 방문

   1. `4`번 노드와 인접한 노드들을 다 방문했기 때문에 Queue에 아무것도 넣지 않는다.

      - `1`번, `2`번 노드는 이미 방문 했으므로 생략

   2. `4`번 노드 탐색 종료

6. `5`번 노드 방문

   1. `5`번 노드와 인접한 노드들을 다 방문했기 때문에 Queue에 아무것도 넣지 않는다.

      - `2`번 노드는 이미 방문 했으므로 생략

   2. `5`번 노드 탐색 종료

</p>
</details>

## Code

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v, e;
vector<bool> isVisited;   // Node 방문 여부 저장
vector<vector<int>> adj;  // 간선 정보 저장

vector<int> BFS(int src)
{
    vector<int> visitOrder;

    queue<int> q;  // 방문 순서 담아두는 queue, FIFO(First In First Out)

    // queue에 src를 넣어주고
    // isVisited[src]를 true로 바꿔준다(방문했다는 의미).
    q.push(src);
    isVisited[src] = true;

    while (!q.empty()) {
        int cur = q.front();  // 가장 오래된 원소를 뽑아낸다.
        q.pop();

        visitOrder.push_back(cur);  // 방문 중인 node를 visitOrder에 추가한다.

        int size = adj[cur].size();  // cur 노드에 연결되어 있는 다른 노드의 개수
        for (int i = 0; i < size; ++i) {
            int next = adj[cur][i];
            // next를 이미 방문한 적이 있다면
            if (isVisited[next]) {
                continue;
            }
            // 방문한 적이 없다면 queue에 넣어준다.
            else {
                isVisited[next] = true;
                q.push(next);
            }
        }
    }

    return visitOrder;
}

int main()
{
    cin >> v >> e;               // Node(Vertex), Edge
    adj.resize(v);               // Init (size of node)
    isVisited.resize(v, false);  // Init (size of node)

    for (int i = e; i > 0; --i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);  // v1 to v2
        adj[v2].push_back(v1);  // v2 to v1
    }

    vector<int> visitOrder = BFS(0);
    cout << "Visit : ";
    int vSize = visitOrder.size() - 1;  // 마지막 -> 제거하기 위해 -1
    for (int i = 0; i < vSize; ++i) {
        cout << visitOrder[i] << " -> ";
    }
    cout << visitOrder.back() << '\n';

    return 0;
}
```
