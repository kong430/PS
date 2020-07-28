#include <iostream>
#include <algorithm>
using namespace std;

int dp[31][31];

int main(void) {
	int T, N, M;
	cin >> T;

	while (T--) {
		cin >> N >> M;

		dp[0][0] = dp[0][1] = dp[1][0] = 0;
		for (int i = 1; i <= M; i++) dp[i][i] = 1;
		for (int i = 1; i <= M; i++) dp[1][i] = i;

		for (int i = 2; i <= N; i++) {
			for (int j = i + 1; j <= M; j++) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}
		cout << dp[N][M] << '\n';
	}
	return 0;
}