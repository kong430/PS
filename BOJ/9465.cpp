#include <iostream>
#include <algorithm>
using namespace std;

int sti[2][100005];
int dp[2][100005];

int main(void) {
	int T, n;
	cin >> T;

	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> sti[0][i];
		for (int i = 1; i <= n; i++) cin >> sti[1][i];

		dp[0][0] = 0;
		dp[0][1] = sti[0][1];
		dp[1][1] = sti[1][1];

		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sti[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sti[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}