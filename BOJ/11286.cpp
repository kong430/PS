#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<pair<int, int>> pq;
    int N, x;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;

        if (!x && pq.empty())
            cout << 0 << '\n';
        else if (!x)
        {
            cout << -pq.top().second << '\n';
            pq.pop();
        }
        else
            pq.push({ -abs(x), -x });
    }
    return 0;
}