#include <iostream>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int R, C, mx = 0;
char square[21][21];
bool visited[26];	//방문했던 알파벳인지를 체크

void dfs(int x, int y, int cnt) {
	mx = max(mx, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			if (!visited[square[nx][ny] - 'A']) {
				visited[square[nx][ny] - 'A'] = true;
				dfs(nx, ny, cnt + 1);
				visited[square[nx][ny] - 'A'] = false;
			}
		}
	}
}

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> square[i][j];
		}
	}

	visited[square[0][0]-'A'] = true; //무조건 첫칸에서 출발
	dfs(0, 0, 1);
	cout << mx;

	return 0;
}