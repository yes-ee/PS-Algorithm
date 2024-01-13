#include <iostream>
#include <string>
using namespace std;

int n, m, cnt;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> s;

	for (int i = 0; i < m - 2 * n; i++) {
		if (s[i] == 'I') {
			int len = 0;
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				len++;
				i = i + 2;
				if (len == n)	{
					len--;
					cnt++;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}