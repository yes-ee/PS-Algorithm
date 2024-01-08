#include <iostream>

using namespace std;

char ans[3072][6143];
int n;

void re(int x, int y, int n) {
	if (n == 3) {
		ans[y][x + 2] = '*';
		ans[y + 1][x + 1] = '*';
		ans[y + 1][x + 3] = '*';
		for (int i = 0; i < 5; i++)
			ans[y + 2][x + i] = '*';
		return;
	}

	re(x + n/2, y, n/2);
	re(x, y + n/2, n/2);
	re(x + n, y + n/2, n/2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int len = n * 2 - 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len; j++)
			ans[i][j] = ' ';
	}

	re(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len; j++)
			cout << ans[i][j];
		cout << "\n";
	}	

	return 0;
}
