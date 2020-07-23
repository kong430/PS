#include <iostream>
using namespace std;

int mat1[101][101];
int mat2[101][101];
int result[101][101];

int main()
{
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat1[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> mat2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}