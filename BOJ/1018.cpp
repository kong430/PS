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

	/*brute force, ��ü ��ȸ�ϸ� 8*8 ũ�� ������ (0,0): W �������� count.
	W,B / B,W ���̽� �˻� ��� �ݴ��� ��츦 8*8 - count �� Ȯ���Ͽ� �ּ� ����*/
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