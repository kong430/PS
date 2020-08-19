#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[200001];
int dist[200001];

int main(void)
{
	priority_queue<pair<int, int>> pq;

	int V, E, K;
	cin >> V >> E >> K;
	for ( int i = 0; i < E; i++ )
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	for ( int i = 1; i <= V; i++ ) dist[i] = 1e9;

	dist[K] = 0;
	pq.push(make_pair(0, K));

	while ( !pq.empty() )
	{
		int now = pq.top().second;
		int nowdist = -pq.top().first;
		pq.pop();

		for ( pair<int, int> next : graph[now] )
		{
			if ( dist[next.first] >= nowdist + next.second )
			{
				dist[next.first] = nowdist + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}

	for ( int i = 1; i <= V; i++ )
	{
		if ( dist[i] == 1e9 ) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}

	return 0;
}