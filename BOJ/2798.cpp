#include <iostream>
using namespace std;
int card[105];

/*brute force, 모든 카드 조합 고려*/
int main(void) {
	int N, M;
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int tmp = 0;
				tmp = card[i] + card[j] + card[k];
				if (tmp <= M && tmp >= ans)
					ans = tmp;
			}
		}
	}
	cout << ans;

	return 0;
}