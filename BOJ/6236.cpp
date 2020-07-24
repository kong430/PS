#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int N, M;

/*binary search*/

int cal(int limit) {
	int ans = 1;
	int now = 0;	//이번 출금의 total 소비금액

	for (int i = 0; i < N; i++) {
		if (now + arr[i] > limit) {	//돈이 부족해지면 출금 후 사용
			ans++;
			now = arr[i];
		}
		else now += arr[i];
	}
	return ans;
}

int main(void) {
	cin >> N >> M;
	int start = 1;
	int end = 1e9;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		start = max(start, arr[i]);
	}

	while (start < end) {
		int mid = (start + end) / 2;
		if (cal(mid) > M) start = mid + 1;
		else end = mid;
	}

	cout << start;
	return 0;
}