#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int region[101][101];
int visited[101][101];
int N, mx = 0, result = 0;
int id = 0;

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visited[nx][ny] && region[nx][ny] > mx) dfs(nx, ny);
		}
	}
}

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> region[i][j];
			mx = max(mx, region[i][j]);
		}
	}

	while (mx >= 0) {
		//√ ±‚»≠
		id = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) visited[i][j] = false;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && region[i][j] > mx) id++, dfs(i, j);
			}
		}
		result = max(result, id);
		mx--;
	}

	cout << result << '\n';

	return 0;
}