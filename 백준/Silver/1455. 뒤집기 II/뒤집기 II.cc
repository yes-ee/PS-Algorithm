#include <iostream>
#include <string>

using namespace std;

int n, m;
int arr[100][100];
string s;
int cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j];
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (arr[i][j] % 2) {
				cnt++;
				for (int y = 0; y <= i; y++) {
					for (int x = 0; x <= j; x++)
						arr[y][x]++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}