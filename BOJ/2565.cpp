#include <iostream>
#include <algorithm>
using namespace std;

int dp[101];

int main(void) {
	pair<int, int> p[101];
	int N, left, right, Max = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> left >> right;
		p[i] = make_pair(left, right);
		dp[i] = 1;
	}
	sort(p, p + N);
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i].second > p[j].second && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				Max = max(dp[i], Max);
			}
		}
	}
	cout << N - Max;
	return 0;
}