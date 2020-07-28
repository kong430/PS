#include <iostream>
#include <queue>
#include <functional>
using namespace std;

/*최대힙, 최소힙 동시 사용, 최대힙의 top에 중간값 위치*/

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int N;
	cin >> N;
	while (N--) {
		int x;
		cin >> x;
		if (max_heap.size() == min_heap.size()) max_heap.push(x);
		else min_heap.push(x);

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int tmp = max_heap.top();
			max_heap.pop();
			max_heap.push(min_heap.top());
			min_heap.pop();
			min_heap.push(tmp);
		}
		cout << max_heap.top() << '\n';
	}
	return 0;
}