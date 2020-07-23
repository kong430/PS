#include <iostream>
using namespace std;

int arr[130][130];
int white = 0, blue = 0;

void quad(int n, int x, int y) {
	if (n == 1) {
		(arr[x][y] == 1) ? blue++ : white++;
		return;
	}

	bool chk = false;
	int tmp = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != tmp){
				chk = true;
				break;
			}
		}
	}

	if (chk == false) {
		(arr[x][y] == 1) ? blue++ : white++;
		return;
	}
	else {
		quad(n / 2, x, y);
		quad(n / 2, x + n / 2, y);
		quad(n / 2, x, y + n / 2);
		quad(n / 2, x + n / 2, y + n / 2);
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
	cout << white << '\n' << blue;
	return 0;
}