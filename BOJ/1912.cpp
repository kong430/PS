#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int dp[100005];

int main(void) {
	int N, Max = -1e9;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	Max = dp[0] = arr[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		Max = max(Max, dp[i]);
	}
	cout << Max;
	return 0;
}