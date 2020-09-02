#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> v[1001];
queue<pair<int, int>> ans;
int dist[1001];
int p[1001];
int N, M, cnt = 0;

void dijkstra(int start)
{
	dist[1] = 0;
	pq.push(make_pair(0, 1));

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

				p[next.first] = now;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for ( int i = 0; i <= N; i++ ) dist[i] = 1e9;
	for ( int i = 0; i < M; i++ )
	{
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
	}

	dijkstra(1);

	cout << N - 1 << '\n';
	for ( int i = 2; i <= N; i++ )
	{
		cout << p[i] << ' ' << i << '\n';
	}

	return 0;
}