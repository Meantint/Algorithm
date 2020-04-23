// 출처 : https://pangtrue.tistory.com/71

#include <iostream>
#include <cmath>

using namespace std;

int N;
int cnt = 0;
int* cols;	// cols[level]은 level 번째 깊이(행)에서 몇 번째 열에 퀸이 놓였는지를 저장

bool isPromising(int level) {
	for (int i = 1; i < level; ++i) {
		if (cols[i] == cols[level])				// 같은 열에 놓였는지를 검사
			return false;
		else if ((level - 1) == abs(cols[level] - cols[i]))	// 같은 대각선에 놓였는지를 검사
			return false;
	}
	return true;
}

// 현재 어떤 level(깊이)인지 입력 받음
void queens(int level) {
	if (!isPromising(level))
		return;
	else if (level == N) {
		cnt += 1;
		return;
	}
	for (int col = 1; col <= N; ++col) {
		cols[level + 1] = col;
		queens(level + 1);
	}
}

int main()
{
	cin >> N;
	cols = new int[N + 1];

	for (int i = 0; i <= N; ++i)
		cols[i] = 0;
	queens(0);
	cout << cnt << "\n";

	delete[] cols;
	return 0;
}
