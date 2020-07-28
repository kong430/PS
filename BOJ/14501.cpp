#include <iostream>
#include <algorithm>
using namespace std;

/* dp[i] = i일까지의 최대 수입*/

int dp[16];
int T[16], P[16];

int main(void) {
	int N, mx = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;
		
		dp[i + T] = max(dp[i] + P, dp[i + T]);	//i번째날 상담 수행했을 경우 i+T날에 돈을 받음
		dp[i + 1] = max(dp[i], dp[i + 1]); //i번째날 상담 수행하지 않았을 경우 다음날에 둘 중 최댓값 선택
		mx = max(mx, dp[i + 1]);
	}

	cout << mx;
	return 0;
}