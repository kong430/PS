#include <iostream>
using namespace std;
bool arr[10005];

//�����ѹ� �Ǻ� �Լ�
int self(int n) {
	int sum = n;	//�ڱ��ڽ� ���� ����
	while (1) {	//�� �ڸ��� ����
		if (n == 0) break;
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int main(void) {

	for (int i = 1; i <= 10000; i++) {
		int tmp = self(i);

		if (tmp <= 10000) {
			arr[tmp] = true;	//������ ���� �� true�� ����
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) printf("%d\n", i);
	}
	return 0;
}