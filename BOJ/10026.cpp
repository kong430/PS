#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char map[101][101];
int visited[101][101];
int N, cnt1 = 0, cnt2 = 0;

void dfs1(int x, int y) {
	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] == map[x][y] && !visited[nx][ny]) {
				dfs1(nx, ny);
			}
		}
	}
}

void dfs2(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] == map[x][y] && !visited[nx][ny]) {
				dfs2(nx, ny);
			}
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) cnt1++, dfs1(i, j);
		}
	}

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) cnt2++, dfs2(i, j);
		}
	}

	cout << cnt1 << ' ' << cnt2;
	return 0;
}