#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> vec[101];
int visited[101];

int main(void)
{
	int n, m, cnt = -1;
	cin >> n >> m;
	
	for ( int i = 0; i < m; i++ )
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	q.push(1);

	while ( !q.empty() )
	{
		int now = q.front();
		q.pop();

		for ( int i = 0; i < vec[now].size(); i++ )
		{
			if ( !visited[vec[now][i]] )
				q.push(vec[now][i]), visited[vec[now][i]] = true, cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}