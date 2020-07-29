#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool visited[1001];

/*���� ��� -> ���� X, ������ �̷�� �� ���� ��� ����ǥ�� �ʿ�*/

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