#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> com[101];
bool visited[101];
int dist[101][101];
int N, M, cnt = 0;

void dfs(int node)
{
	com[cnt].push_back(node);
	visited[node] = true;
	for (int i = 1; i <= N; i++ )
	{
		if ( dist[node][i] != 1e9 && dist[node][i] != 0 && !visited[i] )
		{
			dfs(i);
		}
	}
}

void clear()
{
	for ( int i = 0; i <= N; i++ )
	{
		for ( int j = 0; j <= N; j++ )
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
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	
	for ( int i = 1; i <= N; i++ )
	{
		if ( !visited[i] )
		{
			cnt++;
			dfs(i);
		}
	}
	floyd();
	cout << cnt << '\n';

	//의사전달시간 중 "최댓값"이 "최소"가 되도록 선정
	int Mx[101], num = 0;
	vector<int> repre;
	for ( int c = 1; c <= cnt; c++ )
	{
		int Mn = 1e9;
		for ( int i = 0; i < com[c].size(); i++ )
		{
			Mx[i] = 0;
			for ( int j = 0; j < com[c].size(); j++ )
			{
				Mx[i] = max(Mx[i], dist[com[c][i]][com[c][j]]);
			}
			if ( Mx[i] < Mn )
			{
				Mn = Mx[i];
				num = com[c][i];
			}
		}
		repre.push_back(num);
	}
	sort(repre.begin(), repre.end());
	for ( int i = 0; i < repre.size(); i++ )
	{
		cout << repre[i] << '\n';
	}

	return 0;
}