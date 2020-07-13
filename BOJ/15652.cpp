#include <iostream>
using namespace std;

int N, M;
int ans[10];

void dfs(int index, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = index; i < N; i++) {
        ans[depth] = i + 1;
        dfs(i, depth + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> N >> M;
    dfs(0, 0);
}