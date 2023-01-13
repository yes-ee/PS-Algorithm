#include <iostream>
#define MAX 1025
using namespace std;

int sum[MAX][MAX];
int arr[MAX][MAX];
int x2, y2, x3, y3, n, m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x2 >> y2 >> x3 >> y3;
		cout << sum[x3][y3] - sum[x2-1][y3] -sum[x3][y2-1]  + sum[x2-1][y2-1]<< "\n";
	}

	return 0;
}
