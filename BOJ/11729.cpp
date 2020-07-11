#include <iostream>
using namespace std;

/* n-1���� 3���� ���� 2������ �ű��, 1���� �ִ� ���� ū ���� 3������ �ű� ��,
2���� �ִ� n-1���� 1���� ���� 3������ �÷� ���� ����*/
void hanoi(int n, int from, int bypass, int to) {
	if (n == 1)
		cout << from << " " << to << "\n";
	else {
		hanoi(n - 1, from, to, bypass);
		cout << from << " " << to << "\n";
		hanoi(n - 1, bypass, from, to);
	}
}

int main(void) {
	int N;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	hanoi(N, 1, 2, 3);
	return 0;
}