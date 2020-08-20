#include <iostream>
using namespace std;

int dp[105][105];

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			dp[i][j] = 1e9;
		}
		dp[i][i] = 0;
	}
	for ( int i = 1; i <= m; i++ )
	{
		cin >> a >> b >> c;
		if ( c <= dp[a][b] )
		{
			dp[a][b] = c;
		}
	}
	for ( int k = 1; k <= n; k++ ) //k번 도시를 중간 지점으로 포함시켰을 경우
	{
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				if ( dp[i][j] > dp[i][k] + dp[k][j] )
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			if ( dp[i][j] != 1e9 )
				cout << dp[i][j] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
}