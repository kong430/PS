#include <iostream>
#include <vector>
using namespace std;

long long dist[501];	
bool flag;
vector<pair<int, int>> v[501]; 

int main(void)
{
	int N, M;
	cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
	}

	for ( int i = 1; i <= N; i++ )
		dist[i] = 1e9;

	dist[1] = 0;
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			for ( pair<int, int> n : v[j] )
			{
				if ( dist[j] != 1e9 && dist[n.first] > n.second + dist[j] ) //출발정점이 최소 한번 업데이트 된 정점일 때만 연결된 점 업데이트
				{
					dist[n.first] = n.second + dist[j];
					if ( i == N ) flag = true; //음수 사이클 판별
				}
			}
		}
	}

	if ( flag ) cout << -1;
	else
	{
		for ( int i = 2; i <= N; i++ )
		{
			if ( dist[i] == 1e9 ) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}