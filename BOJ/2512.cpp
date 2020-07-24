#include <iostream>
#include <algorithm>
using namespace std;

int budget[10005];
int N, M;

bool divide(int n) {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		if (n >= budget[i]) tmp += budget[i];
		else tmp += n;
	}
	if (tmp <= M) return true;
	else return false;
}

int main(void) {
	int mn = 0, mx = 0, result = 0;
	int total = 0, Max = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		total += budget[i];
		Max = max(Max, budget[i]);
	}
	cin >> M;
	mx = M;

	sort(budget, budget + N);
	
	//총액보다 합이 작을 때 예외처리
	if (M >= total) {
		cout << Max;
		return 0;
	}

	int mid = 0;
	while (mn <= mx) {
		mid = (mn + mx) / 2;
		if (divide(mid)) {
			result = max(result, mid);
			mn = mid + 1;
		}
		else mx = mid - 1;
	}

	cout << result;
	return 0;
}