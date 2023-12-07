#include <iostream>
#include <string>

using namespace std;

int arr[64][64];

void re(int x, int y, int n) {
	if (n == 1) {
		cout << arr[y][x];
		return;
	}

	int flag = 0;
	int num = arr[y][x];

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] != num) {
				flag = 1;
				n /= 2;
				cout << "(";
				re(x, y, n);
				re(x + n, y, n);
				re(x, y + n, n);
				re(x + n, y + n, n);
				cout << ")";
				return;
			}
		}
	}

	if (!flag)
		cout << num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	re(0, 0, n);
}