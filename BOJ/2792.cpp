#include <iostream>
#include <algorithm>
using namespace std;

/*해당 갯수를 N명 이하에게 나누어줄 수 있는지 판별*/

int color[300005];
int N, M;

bool divide(int n) {
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cnt += color[i] / n;
		if (color[i] % n) cnt++;
	}
	return N >= cnt;
}

int main(void) {
	int mn = 1, mx = 1e9;
	int Max = 0, result = 1e9;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> color[i];
		Max = max(Max, color[i]);
	}

	while (mn <= mx) {
		int mid = (mn + mx) / 2;
		if (divide(mid)) {
			result = min(result, mid);
			mx = mid - 1;
		}
		else mn = mid + 1;
	}

	cout << result;
	return 0;
}