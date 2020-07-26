#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	vector<int> up;
	vector<int> down;
	int N, H;
	int mn = 1e9, cnt = 0;
	cin >> N >> H;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		(i % 2 == 0) ? down.push_back(tmp) : up.push_back(tmp);
	}
	sort(down.begin(), down.end());
	sort(up.begin(), up.end());

	for (int i = 1; i <= H; i++) {
		int tmp = 0;
		tmp += down.size() - (lower_bound(down.begin(), down.end(), i) - down.begin());
		tmp += up.size() - (upper_bound(up.begin(), up.end(), H - i) - up.begin());

		if (mn == tmp) cnt++;
		else if (mn > tmp) {
			mn = tmp;
			cnt = 1;
		}
	}

	cout << mn << ' ' << cnt;
	return 0;
}