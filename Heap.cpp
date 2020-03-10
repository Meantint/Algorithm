// 힙 ( heap )
// https://www.weeklyps.com/entry/%ED%9E%99-heap [weekly ps]

#include <iostream>
#include <vector>

using namespace std;

struct max_heap {
	vector<int> h;			// 원소값들을 저장한다. h[i]의 자식 = h[2 * i + 1], h[2 * i + 2]

	void push(int v) {		// 힙에 v를 삽입한다.
		int idx = h.size();	// idx = 삽입한 값이 들어있는 위치
		h.push_back(v);
		while (idx != 0 && h[idx] > h[(idx - 1) / 2]) {
			swap(h[idx], h[(idx - 1) / 2]);
			idx = (idx - 1) / 2;
		}
	}

	int top(void) {			// 힙에서 최대값을 반환한다.
		return h[0];
	}

	void pop(void) {		// 힙에서 최대값을 삭제한다.
		h[0] = h.back();	// 힙의 끝에 있던 값을 루트에 넣는다.
		h.pop_back();		// 의미가 없어진 힙의 끝은 삭제한다.
		int idx = 0;
		while (true) {	
			int child = 2 * idx + 1;		// child = 왼쪽 자식
			if (child >= h.size())	break;		// 자식 노드가 없는 경우, 종료
			if (child + 1 < h.size() && h[child + 1] > h[child])
				child++;			// 오른쪽 자식이 왼쪽 자식보다 클 경우, 오른쪽 자식을 child로 변경
			if (h[idx] >= h[child])	break;		// 자식의 값보다 idx의 값이 더 크거나 같을 경우, 종료
			swap(h[idx], h[child]);			// 자식의 값이 더 클 경우, 스왑
			idx = child;
		}
	}
};
