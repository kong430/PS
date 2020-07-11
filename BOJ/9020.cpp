#include <iostream>
#include <cstring>
using namespace std;

int prime[10005];

int main(void) {
	int T, n;
	memset(prime, 0, sizeof(prime));

	cin >> T;
	for (int i = 2; i < 10000; i++) {
		for (int j = i * i; j < 10000; j += i) {
			prime[j] = 1;
		}
	}

	for (int i = 0; i < T; i++) {
		int cha = 10000, sol = 0;
		cin >> n;
		for (int j = 2; j < n; j++) {
			int tmp = (j < n - j) ? n - 2 * j : 2 * j - n;
			if (!prime[j] && !prime[n - j] && (tmp < cha)) {
				cha = tmp;
				sol = j;
			}
		}
		cout << sol << " " << n - sol << "\n";
	}

	return 0;
}