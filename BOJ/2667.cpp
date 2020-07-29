#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int map[26][26];
bool visited[26][26];
int cnt[630];
int N, idx = 0;

void dfs(int x, int y) {
	//dfs ȣ�� �� �湮 ǥ��
	visited[x][y] = true;
	//�ش� ������ ���� �� ����
	cnt[idx]++;

	//�ش� ��ġ�� �ֺ� Ȯ��
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {	//������ ����� X
			if (!visited[nx][ny] && map[nx][ny]) {	//���̸鼭 �湮�� ���� ���ٸ� �湮
				dfs(nx, ny);
			}
		}
	}
}


int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//��ü map Ž��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//���̸鼭 �湮�� ���� ���ٸ� �湮, ������ȣ �ο� �� Ž��
			if (map[i][j] && !visited[i][j]) idx++,	dfs(i, j);
		}
	}
	sort(cnt + 1, cnt + idx + 1);

	cout << idx << '\n';
	for (int i = 1; i <= idx; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}