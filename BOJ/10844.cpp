#include <iostream>
using namespace std;

int dp[105][11];
long long ans = 0;	//long long 사용

/*i자리의 수 중 j로 끝나는 수*/
int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 0; i < 10; i++) ans += dp[N][i];
	cout << ans % 1000000000;
	return 0;
}