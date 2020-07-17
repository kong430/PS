#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];
int dp[1005];

/*현재 index 전까지의 dp 값들과 해당 arr값을 현재값과 비교*/
int main(void) {
	int N, Max = 1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				Max = max(dp[i], Max);
			}
		}
	}
	cout << Max;
	return 0;
}