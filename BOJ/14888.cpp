#include <iostream>
using namespace std;

int N;
int a[11], op[4];
int Max = -1e9, Min = 1e9;

void cal(int index, int ans, int add, int sub, int mul, int div) {
    if (index == N) {
        if (ans > Max) 
            Max = ans;
        if (ans < Min) 
            Min = ans;
        return;
    }
    if (add) 
        cal(index + 1, ans + a[index], add - 1, sub, mul, div);
    if (sub) 
        cal(index + 1, ans - a[index], add, sub - 1, mul, div);
    if (mul) 
        cal(index + 1, ans * a[index], add, sub, mul - 1, div);
    if (div) 
        cal(index + 1, ans / a[index], add, sub, mul, div - 1);
}

int main() {
    cin>>N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    cal(1, a[0], op[0], op[1], op[2], op[3]);
    cout << Max << '\n' << Min << '\n';
    return 0;
}