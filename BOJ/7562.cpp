#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[8] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[8] = { -2, 2, -1, 1, -2, 2, -1, 1 };

int map[301][301];
int dist[301][301];
int t, l, now_x, now_y, next_x, next_y;

void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(now_x, now_y));

	while ( !q.empty() )
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if ( x == next_x && y == next_y )
		{
			cout << dist[x][y] << '\n';
			return;
		}

		for ( int i = 0; i < 8; i++ )
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ( nx >= 0 && nx < l && ny >= 0 && ny < l )
			{
				if ( !dist[nx][ny] )
					dist[nx][ny] = dist[x][y] + 1, q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	cin >> t;
	
	while ( t-- )
	{
		memset(dist, 0, sizeof(dist));
		cin >> l >> now_x >> now_y >> next_x >> next_y;
		bfs();
	}

	return 0;
}