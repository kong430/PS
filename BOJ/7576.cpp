#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int day[1001][1001];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main(void) {
	queue<pair<int, int>> q;

	int M, N, ans = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			day[i][j] = -1;
			if (map[i][j] == 1) {	//map에서 1인 지점들은 시작점을 의미하므로 큐에 삽입
				q.push(make_pair(i, j));
				day[i][j] = 0;
			}
		}
	}

	//bfs
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!map[nx][ny] && day[nx][ny] == -1) {	//토마토가 익지 않고, 방문하지 않은 곳이면
					map[nx][ny] = 1;	//토마토를 익게 함
					day[nx][ny] = day[x][y] + 1;	//날짜를 1 증가시킴
					q.push(make_pair(nx, ny));	//큐에 삽입
				}
			}
		}
	}

	//dist의 최대값 계산. 모두 다 익어있었다면 day는 -1이므로 ans = 0
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, day[i][j]);
		}
	}

	//토마토가 익지 않은 곳이 있다면 ans = -1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j] && day[i][j] == -1) ans = -1;
		}
	}

	cout << ans;

	return 0;
}