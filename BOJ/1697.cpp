#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//visited 배열 대신 time배열만 사용. 0이 아닌 곳은 다 방문한 곳으로 간주하는 방식도 O
int visited[100005];
int time[100005];

int main(void) {
	queue<int> q;

	int N, K, now = 0;
	cin >> N >> K;
	memset(time, 0, sizeof(time));

	q.push(N);
	visited[N] = true;

	while (!q.empty()) {
		now = q.front();
		q.pop();

		if (now == K) break;

		//앞의 조건이 우선적으로 만족되어야 함. 그렇지 않을 시 런타임에러
		/*if (now + 1 <= 100000 && !visited[now + 1])
			q.push(now + 1), time[now + 1] = time[now] + 1, visited[now + 1] = true;
		if (now - 1 >= 0 && !visited[now - 1])
			q.push(now - 1), time[now - 1] = time[now] + 1, visited[now - 1] = true;
		if (now * 2 <= 100000 && !visited[now * 2])
			q.push(now * 2), time[now * 2] = time[now] + 1, visited[now * 2] = true;*/

		for (int nx : {now - 1, now + 1, 2 * now}) {
			if (nx < 0 || nx > 100000 || visited[nx]) continue;
			q.push(nx), time[nx] = time[now] + 1, visited[nx] = true;
		}
	}

	cout << time[now];
	return 0;
}