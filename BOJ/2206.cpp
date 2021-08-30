/*
* 가중치가 없는 최단경로 -> bfs
* 벽을 부순 여부도 각 노드에서 저장 필요 -> q와 dist 배열에 모두 포함
*/
#include <stdio.h>
#include <queue>
using namespace std;

int n, m;
int arr[1005][1005];
int dist[1005][1005][2];

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };

struct map {
	int y, x, w;
};

int bfs() {
	queue<map> q;
	q.push({ 1, 1, 0 });
	dist[1][1][0] = 1;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int w = q.front().w;
		q.pop();

		if (y == n && x == m) return dist[y][x][w];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny > 0 && ny <= n && nx > 0 && nx <= m) {
				if (!dist[ny][nx][w]) {
					if (arr[ny][nx] == 0) {
						dist[ny][nx][w] = dist[y][x][w] + 1;
						q.push({ ny, nx, w });
					}
					if (arr[ny][nx] == 1 && w == 0) {
						dist[ny][nx][1] = dist[y][x][w] + 1;
						q.push({ ny, nx, 1 });
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
	printf("%d", bfs());
}
