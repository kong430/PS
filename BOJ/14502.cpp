/*
* n, m 범위가 작기 때문에 완전탐색 가능
* backtracking & bfs 로 구현
* 1. backtracking으로 n*m 중 중복없이 3개 선택하여 벽 세움
* 2. 3개 설치 후 bfs로 바이러스 확산시킴
* 3. 남은 빈칸의 수 계산하여 최댓값이라면 갱신
*/

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, Max = 0;
int arr[9][9];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

int bfs() {
	int ans = 0;
	int tmp_arr[9][9];
	queue < pair<int, int>> tmp_q = q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_arr[i][j] = arr[i][j];
		}
	}
	while (!tmp_q.empty()) {
		int y = tmp_q.front().first;
		int x = tmp_q.front().second;
		tmp_q.pop();

		if (tmp_arr[y][x] == 1) continue;

		tmp_arr[y][x] = 2;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (tmp_arr[ny][nx] == 0 && ny <n && nx <m && ny >= 0 && nx >= 0) tmp_q.push({ ny, nx });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_arr[i][j] == 0) ans++;
		}
	}

	return ans;
}

void dfs(int cnt) {
	if (cnt > 3) {
		Max = max(Max, bfs());
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				dfs(cnt + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) q.push({ i, j });
		}
	}
	dfs(1);
	printf("%d", Max);
}
