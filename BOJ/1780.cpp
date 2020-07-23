#include <iostream>
using namespace std;

int arr[2200][2200];
int neg = 0, zero = 0, one = 0;

void quad(int n, int x, int y) {
	if (n == 1) {
		(arr[x][y] == -1 )? neg++ : (arr[x][y] == 0) ? zero++ : one++;
		return;
	}

	bool chk = false;
	int tmp = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != tmp) {
				chk = true;
				break;
			}
		}
	}

	if (chk == false) {
		(arr[x][y] == -1) ? neg++ : (arr[x][y] == 0) ? zero++ : one++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				quad(n / 3, x + n / 3 * i, y + n / 3 * j);
			}
		}
	}
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	quad(N, 0, 0);
	cout << neg << '\n' << zero << '\n' << one;
	return 0;
}