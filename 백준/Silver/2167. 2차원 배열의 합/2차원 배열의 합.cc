#include <iostream>
#include <vector>

using namespace std;

int n, m;
int k, i, j, x, y;
int arr[301][301];
long long sum[301][301];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}

	cin >> k;

	while (k--) {
		cin >> i >> j >> x >> y;

		cout << sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] << "\n";
	}

	return 0;
}