#include <iostream>
#include <deque>
using namespace std;

int arr[51];

int main(void) {
	deque<int> dq;

	int N, M, ans = 0;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) dq.push_back(i);

	while (M--) {
		int idx = 0;
		cin >> idx;

		int cur = 1;

		for (deque<int>::iterator iter = dq.begin(); iter < dq.end(); iter++) {
			if (*iter == idx) break;
			cur++;
		}

		int left = cur - 1;
		int right = dq.size() - cur + 1;

		if (left < right) {
			for (int j = 0; j < left; j++) {
				int num = dq.front();
				dq.pop_front();
				dq.push_back(num);
				ans++;
			}
			dq.pop_front();
		}
		else {
			for (int j = 0; j < right; j++) {
				int num = dq.back();
				dq.pop_back();
				dq.push_front(num);
				ans++;
			}
			dq.pop_front();
		}
	}
	cout << ans;
	return 0;
}