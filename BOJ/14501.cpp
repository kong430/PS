#include <iostream>
#include <algorithm>
using namespace std;

/* dp[i] = i�ϱ����� �ִ� ����*/

int dp[16];
int T[16], P[16];

int main(void) {
	int N, mx = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;
		
		dp[i + T] = max(dp[i] + P, dp[i + T]);	//i��°�� ��� �������� ��� i+T���� ���� ����
		dp[i + 1] = max(dp[i], dp[i + 1]); //i��°�� ��� �������� �ʾ��� ��� �������� �� �� �ִ� ����
		mx = max(mx, dp[i + 1]);
	}

	cout << mx;
	return 0;
}