// 유니온 파인드 ( Union - find )
// https://www.weeklyps.com/entry/%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9C-Unionfind [weekly ps]
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000;

struct union_find_tree {
	vector<int> parent;
	vector<int> height;
	vector<int> group_size;

	void init(int uf_n) {			// 요소 uf_n개로 초기화
		parent.clear();
		height.clear();
		group_size.clear();
		for (int i = 0; i < uf_n; i++) {
			parent.push_back(i);
			height.push_back(0);
			group_size.push_back(1);
		}
	}
	int get_root(int now) {
		if (parent[now] == now)	return now;
		return parent[now] = get_root(parent[now]);
	}
	void merge(int v1, int v2) {
		v1 = get_root(v1);
		v2 = get_root(v2);
		if (v1 == v2)	return;
		if (height[v1] < height[v2])	swap(v1, v2);
		parent[v2] = v1;
		group_size[v1] += group_size[v2];
		if (height[v1] == height[v2])	height[v1]++;
	}
}uf;

int main()
{
	return 0;
}
