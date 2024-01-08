#include <iostream>

using namespace std;

char ans[6561][6561];
int n;

void re(int y, int x, int n) {
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					continue;
				ans[y + i][x + j] = '*';
			}
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			re(y + n * i, x + n * j, n / 3);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = ' ';
		}
	}

	re(0, 0, n / 3);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}

	return 0;
}