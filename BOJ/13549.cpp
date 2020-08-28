#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;

int time[100005];

int main(void)
{
	int N, K;
	cin >> N >> K;
	memset(time, -1, sizeof(time));

	deque<int> dq;
	dq.push_back(N);
	time[N] = 0;

	while ( !dq.empty() )
	{
		int now = dq.front();
		dq.pop_front();

		if ( now == K ) break;

		// if문의 우선순위는 now * 2 가 가장 높음
		if ( now * 2 <= 100000 && time[now * 2] == -1 )
			dq.push_front(now * 2), time[now * 2] = time[now];
		if ( now + 1 <= 100000 && time[now + 1] == -1 )
			dq.push_back(now + 1), time[now + 1] = time[now] + 1;
		if ( now - 1 >= 0 && time[now - 1] == -1 )
			dq.push_back(now - 1), time[now - 1] = time[now] + 1;
	}

	cout << time[K];
	return 0;
}