#include <iostream>
using namespace std;

int coin[11];

int main(void) {
	int N, K, cnt = 0;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		while (K-coin[i] >= 0) {
			K -= coin[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}