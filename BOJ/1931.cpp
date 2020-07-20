#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*회의 시간이 짧은 순서로 했다가 틀림.
끝나는 시각이 빠른 순, 같다면 시작 시각이 빠른 순*/

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second<b.second) return true;
    else if(a.second>b.second) return false;
    if(a.first<b.first) return true;
    else return false;
}

int main(void) {
	vector<pair<int, int>> v;
	int N, time = 0, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		if (time <= v[i].first) {
			time = v[i].second;
			cnt++;
		}
	}
	
	cout << cnt;
	return 0;
}
