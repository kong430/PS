#include <iostream>
using namespace std;
int dp0[41] = { 1, 0, };
int dp1[41] = { 0, 1, 0, };

//재귀호출 시 O(n^2)으로 시간초과
void fibo(int n) {
	for (int i = 2; i <= n; i++) {
		dp0[i] = dp0[i - 2] + dp0[i - 1];
		dp1[i] = dp1[i - 2] + dp1[i - 1];
	}
	cout << dp0[n] << ' ' << dp1[n] << '\n';
}

int main(void) {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		fibo(N);
	}
	return 0;
}