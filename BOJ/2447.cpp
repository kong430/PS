#include <iostream>
using namespace std;

char star[7000][7000];

/* x, y�� ���簢���� ���۵Ǵ� ���� ��ǥ, n�� 1�϶����� ������ �� 1�� �� ����� return*/
void draw(int x, int y, int n) {
	if (n == 1) {
		star[x][y] = '*';
		return;
	}
	//��ü �簢���� 3*3���� �����Ͽ� ������ ���� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue; // ��� �κ��� �������
			draw(x + (n / 3 * i), y + (n / 3 * j), n / 3);
		}
	}
}
int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star[i][j] = ' ';
		}
	}

	draw(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;
}