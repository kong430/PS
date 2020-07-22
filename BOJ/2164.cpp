#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	queue<int> q;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (1) {
		if (q.size() == 1) break;
		q.pop();
		int tmp = q.front();
		if (q.size() == 1) break;
		q.pop();
		q.push(tmp);
	}

	cout << q.front();
	return 0;
}
	