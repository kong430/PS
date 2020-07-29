#include <iostream>
using namespace std;

int num[14];
int tmp[14];
int k;

void dfs(int start, int cnt) {
	if (cnt == 2)
	{
		for (int i = 0; i < 2; i++) cout << tmp[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		tmp[cnt] = num[i];
		dfs(i + 1, cnt + 1);
	}
}

int main(void) {
	while (cin >> k && k) {
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}