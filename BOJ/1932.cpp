#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];

/* 각 층마다 최댓값 저장. 왼쪽, 오른쪽, 나머지 값 case 나눠서 저장*/
int main(void) {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] += dp[i - 1][j];
			else if (i == j) dp[i][j] += dp[i - 1][j - 1];
			else dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans < dp[n - 1][i]) ans = dp[n - 1][i];
	}

	cout << ans;
	return 0;
}