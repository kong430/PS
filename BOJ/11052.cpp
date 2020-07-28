#include <iostream>
#include <algorithm>
using namespace std;

int card[1005];
int dp[1005];

int main(void) {
	int N, mx = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	dp[0] = 0;
	dp[1] = card[1];

	for (int i = 2; i <= N; i++) {
		int tmp = 0;
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}

	cout << dp[N];
	return 0;
}