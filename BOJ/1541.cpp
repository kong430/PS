#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*처음 -를 만난 후의 +는 모두 괄호에 의해 -가 됨*/
int main(void) {
	vector<int> num;
	vector<char> op;
	string st;
	int tmp = 0, ans = 0, flag = 0;
	cin >> st;
	
	for (int i = 0; i <=st.length(); i++) {
		if (!isdigit(st[i]) || st[i]=='\0') {
			num.push_back(atoi(st.substr(tmp, i).c_str()));
			if (st[i] != '\0') op.push_back(st[i]);
			tmp = i+1;
		}
	}
	
	ans = num[0];

	for (int i = 0; i < num.size()-1; i++) {
		if (flag) {
			ans -= num[i + 1]; 
			continue;
		}
		if (op[i] == '+') ans += num[i + 1];
		else if (op[i] == '-') {
			ans -= num[i + 1];
			flag = 1;
		}
	}
	
	cout << ans;
	return 0;
}