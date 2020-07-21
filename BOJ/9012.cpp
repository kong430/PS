#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int T;
	string a;
	
	cin >> T;
	while (T--) {
		cin >> a;
		stack<char> st;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(') st.push(a[i]);
			else if (!st.empty()) st.pop();
			else {
				cout << "NO" << '\n';
				break;
			}
			if (i == a.length() - 1) {
				if (!st.empty()) cout << "NO" << '\n';
				else cout << "YES" << '\n';
			}
		}
	}
	return 0;
}