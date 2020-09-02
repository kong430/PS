#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

priority_queue<pair<int, int>> pq;
queue<int> q;
vector<pair<int, int>> v[1001];
stack<int> ans;
int dist[1001];
int n, m, start, dest, cnt = 0;

void dijkstra(int start)
{
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while ( !pq.empty() )
	{
		int now = pq.top().second;
		int ndist = -pq.top().first;
		pq.pop();

		for ( pair<int, int> next : v[now] )
		{
			if ( dist[next.first] > ndist + next.second )
			{
				dist[next.first] = ndist + next.second;
				pq.push(make_pair(-dist[next.first], next.first));
			}
		}
	}
}

void track(int end)
{
	q.push(end);
	ans.push(end);
	cnt++;

	while ( !q.empty() )
	{
		int now = q.front();
		q.pop();

		bool chk = false;
		int tmp = 0;
		for ( int i = 0; i <= n; i++ )
		{
			for ( pair<int, int> next : v[i] )
			{
				if ( next.first == now && dist[now] == dist[i] + next.second )
				{
					chk = true;
					tmp = i;
				}
			}
		}
		if ( chk )
		{
			ans.push(tmp);
			q.push(tmp);
			cnt++;
			chk = false;
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for ( int i = 0; i <= n; i++ )
	{
		dist[i] = 1e9;
	}

	for ( int i = 0; i < m; i++ )
	{
		int s, d, c;
		cin >> s >> d >> c;
		v[s].push_back(make_pair(d, c));
	}
	cin >> start >> dest;

	dijkstra(start);
	cout << dist[dest] << '\n';

	track(dest);
	cout << cnt << '\n';

	while ( !ans.empty() )
	{
		cout << ans.top() << ' ';
		ans.pop();
	}

	return 0;
}