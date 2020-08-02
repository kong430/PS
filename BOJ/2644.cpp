#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> re[101];
int n, a, b, m;
int dist[101];

int bfs() {
	q.push(a);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		if (now == b) return dist[now];

		for (int i = 0; i < re[now].size(); i++) {
			int next = re[now][i];
			if (dist[next]) continue;
			q.push(next);
			dist[next] = dist[now] + 1;
		}
	}
	return -1;
}

int main(void) {
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		re[x].push_back(y);
		re[y].push_back(x);
	}

	cout << bfs();
	return 0;
}