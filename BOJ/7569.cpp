#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

int map[101][101][101];
int day[101][101][101];
queue<pair<int, pair<int, int>>> q;

int main(void)
{
	int M, N, H, ans = 0;
	cin >> M >> N >> H;

	for ( int i = 0; i < H; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			for ( int k = 0; k < M; k++ )
			{
				cin >> map[i][j][k];
				day[i][j][k] = -1;
				if ( map[i][j][k] == 1 ) q.push(make_pair(i, make_pair(j, k))), day[i][j][k] = 0;
			}
		}
	}
	
	while ( !q.empty() )
	{
		int z = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		for ( int i = 0; i < 6; i++ )
		{
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			if ( nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M )
			{
				if (!map[nz][nx][ny] && day[nz][nx][ny] == -1 )
				{
					map[nz][nx][ny] = 1;
					day[nz][nx][ny] = day[z][x][y] + 1;
					q.push(make_pair(nz, make_pair(nx, ny)));
				}
			}
		}
	}

	for ( int i = 0; i < H; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			for ( int k = 0; k < M; k++ )
			{
				ans = max(ans, day[i][j][k]);
			}
		}
	}

	for ( int i = 0; i < H; i++ )
	{
		for ( int j = 0; j < N; j++ )
		{
			for ( int k = 0; k < M; k++ )
			{
				if ( !map[i][j][k] && day[i][j][k] == -1 ) ans = -1;
			}
		}
	}

	cout << ans;

	return 0;
}