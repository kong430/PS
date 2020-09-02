#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v[501];
priority_queue<pair<int, int>> pq;
vector<int> dist;
int N, M, S, D;

vector<int> dijkstra(int start)
{
	for ( int i = 0; i < N; i++ )
	{
		dist.push_back(i);
		dist[i] = 1e9;
	}

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while ( !pq.empty() )
	{
		int now = pq.top().second;
		int ndist = -pq.top().first;
		pq.pop();

		for ( pair<int, int> next : v[now] )
		{
			if ( next.second != -1 && dist[next.first] > ndist + next.second )
			{
				dist[next.first] = ndist + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}

	return dist;
}

void remove(int start, int end)
{
	queue<int> q;
	q.push(end);

	while ( !q.empty() )
	{
		int now = q.front();
		q.pop();

		for ( int i = 0; i < N; i++ )
		{
			for ( int j = 0; j < v[i].size(); j++ )
			{
				if ( v[i][j].first == now )
				{
					if ( dist[now] == dist[i] + v[i][j].second )
					{
						q.push(i);
						v[i][j].second = -1;
					}
				}
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		cin >> N >> M;
		if ( N == 0 && M == 0 ) break;

		cin >> S >> D;
		for ( int i = 0; i < N; i++ )
		{
			v[i].clear();
		}

		for ( int i = 0; i < M; i++ )
		{
			int U, V, P;
			cin >> U >> V >> P;
			v[U].push_back(make_pair(V, P));
		}

		vector<int> result;
		result = dijkstra(S);
		remove(S, D);
		result = dijkstra(S);

		if ( dist[D] == 1e9 ) cout << "-1\n";
		else cout << dist[D] << '\n';
	}

	return 0;
}