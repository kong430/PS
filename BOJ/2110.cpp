#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*좌표 정렬, 최소 거리는 1 & 최대 거리는 끝-처음 으로 둔 뒤 
이분탐색으로 해당 간격으로 C개(이상) 가능하면 조건 충족, 그 중 최댓값을 찾자*/

vector<int> v;
int N, C;

bool set(int dist) {
	int cnt = 1;
	int prev = v[0];

	for (int i = 1; i < N; i++) {
		if (v[i] - prev >= dist) {
			cnt++;
			prev = v[i];
		}
	}

	if (cnt >= C) return true;
	else return false;

}

int main(void) {
	int mn = 0, mx = 0, result = 0;

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int point;
		cin >> point;
		v.push_back(point);
	}
	sort(v.begin(), v.end());

	mn = 1, mx = v[v.size() - 1] - v[0];
	
	while (mn <= mx) {
		int mid = (mn + mx) / 2;
		if (set(mid)) {
			result = max(result, mid);
			mn = mid + 1;
		}
		else mx = mid - 1;
	}
	
	cout << result;
	return 0;
}