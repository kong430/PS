#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51];
char color[2] = { 'W', 'B' };

int main(void) {
	int N, M;
	int ans = 3000;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	/*brute force, 전체 순회하며 8*8 크기 내에서 (0,0): W 기준으로 count.
	W,B / B,W 케이스 검사 대신 반대의 경우를 8*8 - count 로 확인하여 최소 구함*/
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int cnt = 0;
			for (int x = i; x < i + 8; x++) {
				for (int y = j; y < j + 8; y++) {
					if (board[x][y] != color[(x + y) % 2])
						cnt++;
				}
			}
			cnt = min(cnt, 64 - cnt);
			if (ans > cnt)
				ans = cnt;
		}
	}
	cout << ans;
	return 0;
}