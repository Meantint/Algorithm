#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 각 정점을 방문했는지 여부를 확인
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int here, string path)
{
    // cout << "DFS visits " << here << '\n';
    visited[here] = true;
    // 모든 인접 정점을 순회하기 위한 for문
    for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];
        // 아직 방문한 적 없다면 방문한다.
        if (!visited[there]) {
            cout << "Path to Node " << there << " : ";
            cout << path + " -> " + to_string(there) << '\n';
            dfs(there, path + " -> " + to_string(there));
        }
    }
}

void dfsAll()
{
    visited = vector<bool>(adj.size(), false);
    // 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문한다.
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            cout << "Path to Node " << i << " : " << i << '\n';
            dfs(i, to_string(i));
        }
    }
}

int main()
{
    int V, N;
    cout << "Input\n";
    cout << "-------------------------\n";
    cin >> V >> N;
    adj.resize(V);

    for (int i = 0; i < N; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    cout << "\nOutput\n";
    cout << "-------------------------\n";
    cout << "Num of Vertex & Edge : " << V << ", " << N << '\n';
    for (int i = 0; i < adj.size(); ++i) {
        sort(adj[i].begin(), adj[i].end());
        for (int j = 0; j < adj[i].size(); ++j) {
            if (adj[i][j] < i) continue;
            cout << "(" << i << ", " << adj[i][j] << ")" << '\n';
        }
    }
    cout << "-------------------------\n";
    cout << "Path Order(Starting from Node 0)\n";
    dfsAll();
    cout << "-------------------------\n";

    return 0;
}