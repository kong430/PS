#include <iostream>
#include <vector>
using namespace std;

int dist[401][401];
int n, k;

void clear()
{
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			dist[i][j] = 1e9;
		}
	}
}

void floyd()
{
	for ( int k = 1; k <= n; k++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
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

	cin >> n >> k;
	clear();

	for ( int i = 0; i < k; i++ )
	{
		int x, y;
		cin >> x >> y;
		dist[x][y] = 1;
	}
	floyd();

	int s;
	cin >> s;
	for ( int i = 0; i < s; i++ )
	{
		int a, b;
		cin >> a >> b;

		if ( dist[a][b] != 1e9 ) cout << "-1\n";
		else if ( dist[b][a] != 1e9 ) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}