#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	//�ִ� �ڸ����� 6, ���� �ִ��� 9
	for (int i = N-54; i < N; i++) {
		int tmp = i, sum = i;
		while (tmp) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == N) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}