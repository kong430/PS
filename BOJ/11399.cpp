#include <iostream>
#include <algorithm>
using namespace std;

int time[1005], total[1005];

int main(void) {
	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> time[i];
	}
	sort(time, time + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			total[i] += time[j];
		}
		ans += total[i];
	}
	
	cout << ans;
	return 0;
}