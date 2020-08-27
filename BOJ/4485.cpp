#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int map[126][126];
int dist[126][126];

void dijkstra(int N)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = map[0][0];

	while ( !q.empty() )
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for ( int i = 0; i < 4; i++ )
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
			if ( dist[nx][ny] > dist[x][y] + map[nx][ny] )
			{
				dist[nx][ny] = dist[x][y] + map[nx][ny];
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	int N, cnt = 0;
	cin >> N;

	while ( N )
	{
		cnt++;
		for ( int i = 0; i < N; i++ )
		{
			for ( int j = 0; j < N; j++ )
			{
				cin >> map[i][j];
				dist[i][j] = 1e9;
			}
		}
		dijkstra(N);
		cout << "Problem " << cnt << ": " << dist[N - 1][N - 1] << '\n';
		cin >> N;
	}
	return 0;
}