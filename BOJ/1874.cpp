#include <iostream>
#include <stack>
#include <string>
using namespace std;

int arr[100005];
bool check[100005];

int main(void) {
	stack<int> st;
	int n;
	string ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	st.push(0);

	for (int i = 0; i < n; i++) {
		if (st.top() == arr[i]) {
			st.pop();
			ans += '-';
			continue;
		}
		if (st.top() < arr[i]) {
			for (int j = st.top() + 1; j <= arr[i]; j++) {
				if (check[j] == false) {
					st.push(j);
					check[j] = true;
					ans += '+';
				}
			}
			st.pop();
			ans += '-';
			continue;
		}
		if (st.top() > arr[i]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	for (int i = 0; i < ans.length(); i++) cout << ans[i] << '\n';
	return 0;
}