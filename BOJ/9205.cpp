#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

vector<int> v[101];
bool visited[101];
void dfs(int node)
{
	visited[node] = true;

	for ( int i = 0; i < v[node].size(); i++ )
	{
		int next = v[node][i];
		if ( visited[next] == false ) dfs(next);
	}
}

int main(void)
{
	int t;
	cin >> t;
	while ( t-- )
	{
		for ( int i = 0; i < 101; i++ ) v[i].clear();
		memset(visited, false, sizeof(visited));
		int n;
		cin >> n;

		vector<pair<int, int>> coord;
		for ( int i = 0; i < n + 2; i++ )
		{
			int x, y;
			cin >> x >> y;

			coord.push_back(make_pair(x, y));
		}

		for ( int i = 0; i < n + 2; i++ )
		{
			for ( int j = i + 1; j < n + 2; j++ )
			{
				if ( abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second) <= 1000 )
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		dfs(0);

		if ( visited[n + 1] ) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}