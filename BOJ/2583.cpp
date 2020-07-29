#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int square[101][101];
bool chk[101][101];
int visited[101][101];
int cnt[100001];
int M, N, K;
int id = 0;

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt[id]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (!visited[nx][ny] && !chk[nx][ny]) dfs(nx, ny);
		}
	}
}

int main(void) {
	cin >> M >> N >> K;

	for (int t = 0; t < K; t++) {
		int lx, ly, hx, hy;
		cin >> hx >> hy >> lx >> ly;

		for (int i = hx; i < lx; i++) {
			for (int j = hy; j < ly; j++) {
				chk[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && !chk[i][j]) id++, dfs(i, j);
		}
	}

	sort(cnt + 1, cnt + id + 1);
	cout << id << '\n';
	for (int i = 1; i <= id; i++) cout << cnt[i] << ' ';

	return 0;
}