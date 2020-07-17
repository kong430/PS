#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];
int dp[1005][2];

/*ÁÂ¿ìÀÇ LIS ÇÕ¿¡ -1*/
int main(void) {
	int N, Max = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> arr[i];
		dp[i][0] = dp[i][1] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1) {
				dp[i][0] = dp[j][0] + 1;
			}
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j] && dp[i][1] < dp[j][1] + 1) {
				dp[i][1] = dp[j][1] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		Max = max(Max, dp[i][0] + dp[i][1]);
	}

	cout << Max - 1;
	return 0;
}