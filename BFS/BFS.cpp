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