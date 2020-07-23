#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int ans = 0;

/*슬라이싱 해주지 않는다면 시간초과*/

void search(int n, int x, int y) {
    if (r < x || r >= x + (1 << n) || (c < y || c >= y + (1 << n))) {
        ans += (1 << n * 2);
        return;
    }
	if (n == 1) {
        if (r == x && c == y) {
            cout << ans;
            return;
        }ans++;
        if (r == x && c == y + 1) {
            cout << ans;
            return;
        }ans++;
        if (r == x + 1 && c == y) {
            cout << ans;
            return;
        }ans++;
        if (r == x + 1 && c == y + 1) {
            cout << ans;
            return;
        }ans++;
        return;
	}
	search(n-  1, x, y);
    search(n - 1, x, y + pow(2, n - 1));
    search(n - 1, x + pow(2, n - 1), y);
    search(n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
}

int main(void) {
	cin >> N >> r >> c;
	search(N, 0, 0);
	return 0;
}