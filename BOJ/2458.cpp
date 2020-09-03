#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[501];
int dist[501][501];

int main(void)
{
	int N, M, ans = 0;
	cin >> N >> M;

	for ( int i = 0; i <= N; i++ )
	{
		for ( int j = 0; j <= N; j++ )
		{
			dist[i][j] = 1e9;
		}
	}
	for ( int i = 0; i < M; i++ )
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);

		dist[a][b] = 1;
	}

	for ( int k = 1; k <= N; k++ )
	{
		for ( int i = 1; i <= N; i++ )
		{
			for ( int j = 1; j <= N; j++ )
			{
				if ( dist[i][j] > dist[i][k] + dist[k][j] )
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for ( int i = 1; i <= N; i++ )
	{
		int tmp = 0;
		for ( int j = 1; j <= N; j++ )
		{
			if ( i == j ) continue;
			if ( dist[i][j] != 1e9 || dist[j][i] != 1e9) tmp++;
		}
		if ( tmp == N - 1 ) ans++;
	}

	cout << ans;

	return 0;
}