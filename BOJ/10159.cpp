#include <iostream>
#include <vector>
using namespace std;

int dist[101][101];
int ans[101];
int N, M;

void clear()
{
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			dist[i][j] = 1e9;
		}
		dist[i][i] = 0;
	}
}

void floyd()
{
	for ( int k = 1; k <= N; k++ )
	{
		for ( int i = 1; i <= N; i++ )
		{
			for ( int j = 1; j <= N; j++ )
			{
				if ( dist[i][j] > dist[i][k] + dist[k][j] ) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	clear();

	for ( int i = 0; i < M; i++ )
	{
		int x, y;
		cin >> x >> y;
		dist[x][y] = 1;
	}
	floyd();

	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			if ( dist[i][j] == 1e9 && dist[j][i] == 1e9 ) ans[i]++;
		}
		cout << ans[i] << '\n';
	}

	return 0;
}