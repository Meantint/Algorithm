#include <iostream>
#include <vector>

using namespace std;

struct Union_Find {
    vector<int> parent, rank;

    // 생성자
    Union_Find(int n) : parent(n), rank(n, 1)
    {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // u 연결되있는 집합의 루트 값을 반환
    int find(int u)
    {
        // 자기 자신이 루트라면 자기 자신을 반환
        if (u == parent[u]) return u;
        // 자기 자신이 루트가 아니라면 find를 재귀 호출
        return parent[u] = find(parent[u]);
    }
    // u가 속한 집합, v가 속한 집합을 하나로 합친다.
    void merge(int u, int v)
    {
        // u, v의 루트 값을 찾는다.
        u = find(u), v = find(v);
        // u와 v가 이미 같은 루트를 가지고 있다면 종료
        if (u == v) return;
        // v의 높이가 u의 높이보다 작다면 swap해준다.
        if (rank[u] > rank[v]) swap(u, v);
        // u의 루트를 v로 변경한다.
        parent[u] = v;
        // v의 높이와 u의 높이가 같다면 v의 높이를 1증가 시킨다.
        if (rank[u] == rank[v]) ++rank[v];
    }
};

int main()
{
    Union_Find uf(5);

    cout << "Now\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < 5; ++i) {
        cout << "uf.parent[" << i << "] : " << uf.parent[i] << " | uf.rank["
             << i << "] : " << uf.rank[i] << '\n';
    }
    cout << "-----------------------------------\n";
    cout << "uf.merge(2, 3)\n";
    uf.merge(2, 3);
    cout << "-----------------------------------\n";
    for (int i = 0; i < 5; ++i) {
        cout << "uf.parent[" << i << "] : " << uf.parent[i] << " | uf.rank["
             << i << "] : " << uf.rank[i] << '\n';
    }
    cout << "-----------------------------------\n";
    cout << "uf.merge(0, 1)\n";
    uf.merge(0, 1);
    cout << "-----------------------------------\n";
    for (int i = 0; i < 5; ++i) {
        cout << "uf.parent[" << i << "] : " << uf.parent[i] << " | uf.rank["
             << i << "] : " << uf.rank[i] << '\n';
    }
    cout << "-----------------------------------\n";
    cout << "uf.merge(2, 4)\n";
    uf.merge(2, 4);
    cout << "-----------------------------------\n";
    for (int i = 0; i < 5; ++i) {
        cout << "uf.parent[" << i << "] : " << uf.parent[i] << " | uf.rank["
             << i << "] : " << uf.rank[i] << '\n';
    }
    cout << "-----------------------------------\n";
    cout << "uf.merge(0, 2)\n";
    uf.merge(0, 2);
    cout << "-----------------------------------\n";
    for (int i = 0; i < 5; ++i) {
        cout << "uf.parent[" << i << "] : " << uf.parent[i] << " | uf.rank["
             << i << "] : " << uf.rank[i] << '\n';
    }
    cout << "-----------------------------------\n";

    return 0;
}