#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adj;

void bfs(int start, vector<int>& distance, vector<int>& parent)
{
    distance = vector<int>(adj.size(), -1);
    parent = vector<int>(adj.size(), -1);

    // 방문할 정점 목록을 유지하는 큐
    queue<int> q;
    distance[start] = 0;
    parent[start] = start;
    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        // here의 모든 인접한 정점을 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            // 처음 보는 정점이면 방문 목록에 집어넣는다.
            if (distance[there] == -1) {
                q.push(there);
                distance[there] = distance[here] + 1;
                parent[there] = here;
            }
        }
    }
}

// v로 부터 시작점까지의 최단 경로를 계산한다.
vector<int> shortestPath(int v, const vector<int>& parent)
{
    vector<int> path(1, v);
    while (parent[v] != v) {
        v = parent[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int v, n;
    cin >> v >> n;
    adj.resize(v);

    for (int i = 0; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    vector<int> dist;
    vector<int> parent;

    bfs(0, dist, parent);
    for (int i = 0; i < dist.size(); ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    vector<int> path = shortestPath(3, parent);
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << ' ';
    }
    cout << '\n';

    return 0;
}