#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int map[101][101];
int dist[101][101];
int N, M;

void dijkstra()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;

	while ( !q.empty() )
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for ( int i = 0; i < 4; i++ )
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
			if ( map[nx][ny] == 1 )
			{
				if ( dist[nx][ny] > dist[x][y] + 1 )
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			if ( map[nx][ny] == 0 )
			{
				if ( dist[nx][ny] > dist[x][y] )
				{
					dist[nx][ny] = dist[x][y];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	cin >> M >> N;
	for ( int i = 0; i < N; i++ )
	{
		for ( int j = 0; j < M; j++ )
		{
			scanf("%1d", &map[i][j]);
			dist[i][j] = 1e9;
		}
	}
	dijkstra();
	cout << dist[N - 1][M - 1];

	return 0;
}