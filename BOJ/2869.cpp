#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a, b, v, ans = 0;

	cin >> a >> b >> v;
	ans = ceil((double)(v - a) / (a - b)) + 1;
	cout << ans;

	return 0;
}