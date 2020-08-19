#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*1->v1->v2->N or 1->v2->v1->N*/

vector<pair<int, int>> graph[801]; 
vector<int> dist;

vector<int> dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	
	fill(dist.begin(), dist.end(), 1e9);
	dist[start] = 0;

	pq.push(make_pair(0, start));

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
	return dist;
}

int main(void)
{
	int N, E, ans = 0;
	cin >> N >> E;
	for ( int i = 0; i < N; i++ )
	{
		dist.push_back(i);
	}

	for ( int i = 0; i < E; i++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back(make_pair(b - 1, c));
		graph[b - 1].push_back(make_pair(a - 1, c));
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> r = dijkstra(0);
	vector<int> rv1 = dijkstra(v1 - 1);
	vector<int> rv2 = dijkstra(v2 - 1);

	if ( (r[v1 - 1] >= 1e9 || rv1[v2 - 1] >= 1e9 || rv2[N - 1] >= 1e9)
		&& r[v2 - 1] >= 1e9 || rv2[v1 - 1] >= 1e9 || rv1[N - 1] >= 1e9 ) cout << -1;
	else ans = min(r[v1 - 1] + rv1[v2 - 1] + rv2[N - 1], r[v2 - 1] + rv2[v1 - 1] + rv1[N - 1]), cout << ans;
	
	return 0;
}