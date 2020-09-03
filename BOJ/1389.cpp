#include <iostream>
#include<algorithm>
using namespace std;

int arr[101][101];
int dp[101][101];
int main()
{
	int N, M, ans = 0, Mn = 1e9;
	cin >> N >> M;
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			if ( i == j ) dp[i][j] = 0;
			else dp[i][j] = 1e9;
		}
	}

	for ( int i = 0; i < M; i++ )
	{
		int A, B;
		cin >> A >> B;
		dp[A][B] = 1;
		dp[B][A] = 1;
	}

	for ( int k = 1; k <= N; k++ )
	{
		for ( int i = 1; i <= N; i++ )
		{
			for ( int j = 1; j <= N; j++ )
			{
				if ( dp[i][j] > dp[i][k] + dp[k][j] )
					dp[i][j] = dp[j][i] = dp[i][k] + dp[k][j];
			}
		}
	}
	for ( int i = 1; i <= N; i++ )
	{
		int tmp = 0;
		for ( int j = 1; j <= N; j++ )
		{
			tmp += dp[i][j];
		}
		if ( tmp < Mn )
		{
			Mn = tmp;
			ans = i;
		}
	}
	cout << ans;

	return 0;
}