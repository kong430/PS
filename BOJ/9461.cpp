#include <iostream>
#include <cstdio>
using namespace std;

/* 가장 큰 N에 대해 int범위를 넘어가는지 확인 필요*/
int long long dp[101];

int main(void) {
	int T, N;
	cin >> T;
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 6; j <= N; j++) {
			dp[j] = dp[j - 5] + dp[j - 1];
		}
		printf("%lld\n", dp[N]);
	}
	return 0;
}