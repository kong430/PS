#include <iostream>
#include <cstdio>
using namespace std;

/* ���� ū N�� ���� int������ �Ѿ���� Ȯ�� �ʿ�*/
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