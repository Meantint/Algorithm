#include <iostream>
#include <queue>
#include <vector>

#define PII pair<int, int>

using namespace std;

int V;
vector<vector<PII>> adj;

vector<int> dijkstra(int start)
{
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을
        // 무시한다.
        if (dist[here] < cost) continue;
        // 인접한 정점들을 모두 검사한다.
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(nextDist, there));
            }
        }
    }

    return dist;
}

int main()
{
    cin >> V;
    adj.resize(V);

    int n;  // 간선 개수
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        int dist;
        cin >> a >> b >> dist;

        adj[a].push_back(make_pair(b, dist));
        adj[b].push_back(make_pair(a, dist));
    }
    vector<int> ans = dijkstra(0);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}