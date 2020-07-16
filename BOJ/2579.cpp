#include <iostream>
#include <algorithm>
using namespace std;
int score[301];
int dp[301];
/*���������� �������� �ٷ� �� ����� ����(�� �� ����X) or ���� ����*/
int main(void) {
	int N;
	cin >> N;
	score[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
		if (i < 3) dp[i] = score[i] + score[i - 1];
	}
	for (int i = 3; i <= N; i++) {
		dp[i] = max(score[i - 1] + dp[i - 3], dp[i - 2]) + score[i];
	}
	cout << dp[N];
	return 0;
}