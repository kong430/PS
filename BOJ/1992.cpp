#include <iostream>
#include <string>
using namespace std;

int arr[65][65];

void quad(int n, int x, int y) {
	if (n == 1) {
		cout << arr[y][x];
		return;
	}

	bool chk = false;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[y][x] != arr[i][j]) {
				chk = true;
				break;
			}
		}
	}
	
	if (!chk) {
		cout << arr[y][x];
		return;
	}

	cout << "(";
	quad(n / 2, x, y);
	quad(n / 2, x + n / 2, y);
	quad(n / 2, x, y + n / 2);
	quad(n / 2, x + n / 2, y + n / 2);
	cout << ")";
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	
	quad(N, 0, 0);
	return 0;
}