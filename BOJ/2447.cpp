#include <iostream>
using namespace std;

char star[7000][7000];

/* x, y는 정사각형이 시작되는 점의 좌표, n이 1일때까지 분할한 후 1일 때 별찍고 return*/
void draw(int x, int y, int n) {
	if (n == 1) {
		star[x][y] = '*';
		return;
	}
	//전체 사각형을 3*3으로 분할하여 각각에 대해 재귀
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue; // 가운데 부분은 비어있음
			draw(x + (n / 3 * i), y + (n / 3 * j), n / 3);
		}
	}
}
int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star[i][j] = ' ';
		}
	}

	draw(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;
}