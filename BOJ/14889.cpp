#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int arr[21][21];
bool check[11];	//�� ���� �迭
int start[11];
int N;
int Min = 1e9;

void sol(int cnt, int here) {
	if (here == N) return;
	if (cnt == N / 2) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i] && check[j])
					ans += arr[i][j];
				else if (!check[i] && !check[j])
					ans -= arr[i][j];
			}
		}
		ans = abs(ans);
		Min = min(Min, ans);
		return;
	}
	//0������ Ȯ���ϸ� ���� �߰� or NOT
	check[here] = true;
	sol(cnt + 1, here + 1);
	check[here] = false;
	sol(cnt, here + 1);
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	sol(0, 0);
	cout << Min;
	return 0;
}