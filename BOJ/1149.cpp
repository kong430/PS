#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005][4];

int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
	}
	//i번째 집을 R, G, B로 칠했을 경우
	for (int i = 1; i < N; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
	return 0;
}