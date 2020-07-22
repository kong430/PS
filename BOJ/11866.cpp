#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	queue<int> q;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) q.push(i);

	cout << '<';

	while (q.size()) {
		for (int i = 1; i < K; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		if (q.size() == 1) cout << q.front() << '>';
		else cout << q.front() << ", ";
		q.pop();
	}

	return 0;
}