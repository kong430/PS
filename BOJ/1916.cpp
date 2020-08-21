#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>> pq;
int dist[1001];

int main(void)
{
	int N, M, a, b;
	cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int s, f, c;
		cin >> s >> f >> c;
		v[s].push_back(make_pair(f, c));
	}
	cin >> a >> b;
	fill(dist, dist + 1001, 1e9);

	dist[a] = 0;
	pq.push(make_pair(0, a));

	while ( !pq.empty() )
	{
		int now = pq.top().second;
		int nowdist = -pq.top().first;
		pq.pop();

		for ( pair<int, int> next : v[now] )
		{
			if ( dist[next.first] > nowdist + next.second )
			{
				dist[next.first] = nowdist + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}
	cout << dist[b];
	
	return 0;
}