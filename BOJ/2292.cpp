#include <iostream>
using namespace std;

int main(void) {
	int N, num = 1, i;
	cin >> N;

	//1:1(6*0개), 2:2~7(6*1개), 3:8~19(6*2개), 4:20~37(6*3개) ...
	for (i = 1; i <= N; i++) {
		num += (i-1) * 6;
		if (N <= num) break;
	}

	cout << i;
	
	return 0;
}