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
	//dfs 호출 시 방문 표시
	visited[x][y] = true;
	//해당 단지의 집의 수 증가
	cnt[idx]++;

	//해당 위치의 주변 확인
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {	//지도를 벗어나지 X
			if (!visited[nx][ny] && map[nx][ny]) {	//집이면서 방문한 적이 없다면 방문
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

	//전체 map 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//집이면서 방문한 적이 없다면 방문, 단지번호 부여 후 탐색
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