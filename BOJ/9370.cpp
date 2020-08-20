#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, m, t;
int s, g, h; //시작점, 교차로
vector<pair<int, int>> v[2001];
int dest[101];
vector<int> dist;
vector<int> ans;

vector<int> dijkstra(int s)
{
	priority_queue<pair<int, int>> pq;

	fill(dist.begin(), dist.end(), 1e9);
	dist[s] = 0;
	pq.push(make_pair(0, s));

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
	return dist;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while ( T-- )
	{
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		for ( int i = 0; i < n; i++ )
			v[i].clear(), dist.push_back(i);

		for ( int i = 0; i < m; i++ )
		{
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			v[a - 1].push_back(make_pair(b - 1, d));
			v[b - 1].push_back(make_pair(a - 1, d));
		}

		vector<int> r = dijkstra(s - 1);
		vector<int> r1 = dijkstra(g - 1);
		vector<int> r2 = dijkstra(h - 1);

		for ( int i = 0; i < t; i++ )
		{
			scanf("%d", &dest[i]);
			if ( r[dest[i] - 1] == r[g - 1] + r1[h - 1] + r2[dest[i] - 1] || 
				r[dest[i] - 1] == r[h - 1] + r2[g - 1] + r1[dest[i] - 1] )
				ans.push_back(dest[i]);
		}
		sort(ans.begin(), ans.end());
		
		for ( int i = 0; i < ans.size(); i++ )
			printf("%d ", ans[i]);
		printf("\n");

		ans.clear();
	}

	return 0;
}