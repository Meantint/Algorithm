// 스택 ( Stack )
// https://www.weeklyps.com/entry/%EC%8A%A4%ED%83%9D-Stack [weekly ps]

#include <iostream>

using namespace std;

const int maxStackSize = 100000;

struct intStack {
	int stackSize = 0;				// 현재 스택에 들어가 있는 자료의 개수
	int repository[maxStackSize];	    		// 자료를 보관할 배열

	int top() {					// 스택의 끝(top)에 있는 자료를 반환
		if (stackSize == 0)			// 스택에 아무것도 들어있지 않다면
			return -1;
		return repository[stackSize - 1];
	}
	void push(int pushData) {			// 스택에 pushData를 삽입
		repository[stackSize++] = pushData;
	}
	void pop() {					// 스택의 끝에 있는 자료를 삭제
		if (stackSize != 0)
			stackSize--;
	}
};

int main()
{
	intStack st;

	st.push(1);
	st.push(2);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;

	return 0;
}
