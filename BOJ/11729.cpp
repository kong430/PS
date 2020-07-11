#include <iostream>
using namespace std;

/* n-1개를 3번을 거쳐 2번으로 옮기고, 1번에 있는 가장 큰 것을 3번으로 옮긴 후,
2번에 있는 n-1개를 1번을 거쳐 3번으로 올려 놓는 과정*/
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