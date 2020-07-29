#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool visited[1001];

/*연결 요소 -> 방향 X, 간선을 이루는 두 정점 모두 연결표시 필요*/

void dfs(int n) {
	visited[n] = true;
	
	for (int i = 0; i < vec[n].size(); i++) {
		if (!visited[vec[n][i]]) dfs(vec[n][i]);
	}
}

int main(void) {
	int N, M, cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) cnt++, dfs(i);
	}

	cout << cnt;
	return 0;
}