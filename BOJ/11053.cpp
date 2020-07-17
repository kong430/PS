#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];
int dp[1005];

/*���� index �������� dp ����� �ش� arr���� ���簪�� ��*/
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