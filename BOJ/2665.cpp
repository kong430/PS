#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int map[51][51];
int dist[51][51];
int n;

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

			if ( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
			if ( map[nx][ny] == 0 )
			{
				if ( dist[nx][ny] > dist[x][y] + 1 )
				{
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			if ( map[nx][ny] == 1 )
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
	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			scanf_s("%1d", &map[i][j]);
			dist[i][j] = 1e9;
		}
	}

	dijkstra();
	cout << dist[n - 1][n - 1];

	return 0;
}