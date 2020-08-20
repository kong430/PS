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
				if ( dist[j] != 1e9 && dist[n.first] > n.second + dist[j] ) //��������� �ּ� �ѹ� ������Ʈ �� ������ ���� ����� �� ������Ʈ
				{
					dist[n.first] = n.second + dist[j];
					if ( i == N ) flag = true; //���� ����Ŭ �Ǻ�
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