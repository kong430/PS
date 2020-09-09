#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> v;
vector<int> cost;
int parent[100001];
int ans = 0;

int find(int x)
{
	if ( parent[x] == -1 ) return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y)
{
	x = find(x), y = find(y);
	if ( x != y ) parent[x] = y;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	for ( int i = 0; i < M; i++ )
	{
		int A, B, C;
		cin >> A >> B >> C;
		v.push_back(make_pair(C, make_pair(A, B)));
	}
	sort(v.begin(), v.end());
	memset(parent, -1, sizeof(parent));

	for ( int i = 0; i < M; i++ )
	{
		if ( find(v[i].second.first) != find(v[i].second.second) )
		{
			uni(v[i].second.first, v[i].second.second);
			cost.push_back(v[i].first);
			ans += v[i].first;
		}
	}
	sort(cost.rbegin(), cost.rend());
	cout << ans - cost[0];

	return 0;
}