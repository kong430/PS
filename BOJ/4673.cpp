#include <iostream>
using namespace std;
bool arr[10005];

//셀프넘버 판별 함수
int self(int n) {
	int sum = n;	//자기자신 먼저 더함
	while (1) {	//각 자리수 더함
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
			arr[tmp] = true;	//생성자 존재 시 true로 변경
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) printf("%d\n", i);
	}
	return 0;
}