#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001] ;
int w[101], v[101];

/*i번째 물건까지 탐색, 무게의 합이 j*/
int main(void) {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << dp[N][K];
	return 0;
}