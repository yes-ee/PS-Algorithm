#include <iostream>

using namespace std;

int n, m;
char arr[100][100];

char convert(char c) {
	if (c == '-')
		return '|';
	if (c == '|')
		return '-';
	if (c == '/')
		return '\\';
	if (c == '\\')
		return '/';
	if (c == '^')
		return '<';
	if (c == '<')
		return 'v';
	if (c == 'v')
		return '>';
	if (c == '>')
		return '^';
	return c;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	char c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			arr[i][j] = convert(c);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[j][m - i - 1];
		}
		cout << "\n";
	}

	return 0;
}