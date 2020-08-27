#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, X, ans = 0;
vector<pair<int, int>> v[1001];

vector<int> dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	vector<int> dist;
	for ( int i = 0; i <= N; i++ )
	{
		dist.push_back(1e9);
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
			if ( dist[next.first] > dist[now] + next.second )
			{
				dist[next.first] = dist[now] + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}
	return dist;
}

int main(void)
{
	cin >> N >> M >> X;
	for ( int i = 0; i < M; i++ )
	{
		int s, e, t;
		cin >> s >> e >> t;
		v[s].push_back(make_pair(e, t));
	}

	vector<int> go[1001];
	for ( int i = 1; i <= N; i++ )
	{
		go[i] = dijkstra(i);
	}
	vector<int> back = dijkstra(X);

	for ( int i = 1; i <= N; i++ )
	{
		ans = max(ans, go[i][X] + back[i]);
	}

	cout << ans;
	return 0;
}