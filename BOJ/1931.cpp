#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*ȸ�� �ð��� ª�� ������ �ߴٰ� Ʋ��.
������ �ð��� ���� ��, ���ٸ� ���� �ð��� ���� ��*/

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
