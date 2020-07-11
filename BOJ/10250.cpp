#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int T, H, W, N;
	int y, x;
	string ans;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		y = (N-1) % H +1;
		x = (N-1) / H + 1;

		/* printf로 한다면 ("%d%02d\n", (n-1)%h+1, (n-1)/h+1 한줄로 가능*/
		ans = to_string(y) + to_string(x);

		if (!(x / 10)) {
			ans = to_string(y) + "0" + to_string(x);
		}
		cout << atoi(ans.c_str()) << endl;
	}

	return 0;
}