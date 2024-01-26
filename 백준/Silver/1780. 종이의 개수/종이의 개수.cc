#include <iostream>

using namespace std;

int n;
int arr[2187][2187];
int cnt[3];

void check(int n, int y, int x) {
	int num = arr[y][x];
	int flag = 0;

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (num != arr[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	n /= 3;

	if (flag) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				check(n, y + n * i, x + n * j);
			}
		}
	} else {
		if (num == -1)
			cnt[0]++;
		else if (num == 0)
			cnt[1]++;
		else
			cnt[2]++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	check(n, 0, 0);

	for (int i = 0; i < 3; i++)
		cout << cnt[i] << "\n";

	return 0;
}
