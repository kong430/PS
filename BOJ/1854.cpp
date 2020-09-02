#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/* 최대 k개까지만 dist를 각각 저장한다 */

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v[1001];
priority_queue<int> dist[1001];

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	
	for ( int i = 0; i < m; i++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
	}

	dist[1].push(0);
	pq.push(make_pair(0, 1));

	while ( !pq.empty() )
	{
		int now = pq.top().second;
		int ndist = -pq.top().first;
		pq.pop();

		for ( pair<int, int> next : v[now] )
		{
			if ( dist[next.first].size() < k || dist[next.first].top() > ndist + next.second )
			{
				if ( dist[next.first].size() == k ) dist[next.first].pop();
				dist[next.first].push(ndist + next.second);
				pq.push(make_pair(-(ndist + next.second), next.first));
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		if ( dist[i].size() < k ) cout << -1 << '\n';
		else cout << dist[i].top() << '\n';
	}

	return 0;
}