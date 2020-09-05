#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int parent[100001], cnt[100001];

int find(int num)
{
	if ( num == parent[num] ) return num;
	return parent[num] = find(parent[num]);
}

void uni(int x, int y)
{
	x = find(x), y = find(y);
	if ( x != y )
	{
		if ( cnt[x] < cnt[y] )
		{
			parent[x] = y;
			cnt[y] += cnt[x];
			cnt[x] = 0;
		}
		else
		{
			parent[y] = x;
			cnt[x] += cnt[y];
			cnt[y] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- )
	{
		int F;
		cin >> F;

		for ( int i = 0; i < 100001; i++ )
		{
			parent[i] = i;
			cnt[i] = 1;
		}

		map<string, int> person;
		int idx = 1;
		for ( int i = 0; i < F; i++ )
		{
			string a, b;
			cin >> a >> b;

			//새로 나온 이름이라면 인덱스 부여
			if ( person.count(a) == 0 ) person[a] = idx++;
			if ( person.count(b) == 0 ) person[b] = idx++;

			int pa = find(person[a]);
			int pb = find(person[b]);

			if ( pa == pb ) cout << max(cnt[pa], cnt[pb]) << '\n';
			else
			{
				uni(pa, pb);
				cout << max(cnt[pa], cnt[pb]) << '\n';
			}
		}
	}

	return 0;
}