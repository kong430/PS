#include <iostream>
using namespace std;

int main(void) {
	int N, ans = 0;
	cin >> N;

	//3�� ������ ���ʷ� 5�� ����� ������ ��� ����
	while (N>=0){
		if (N % 5 == 0) {
			ans += N / 5;
			break;
		}
		else {
			N -= 3;
			ans++;
		}
		if (N!=0 && N < 3) {
			ans = -1;
			break;
		}
	}

	cout << ans;

	return 0;
}