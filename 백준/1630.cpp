#include <iostream>
#define MAX 128

using namespace std;

int paper[MAX][MAX];
int cnt[2];	//0 white 1 blue

void solve(int n, int y, int x) {
	int color = paper[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (color != paper[i][j]) {
				solve(n / 2, y, x);
				solve(n/2, y, x + n/2);
				solve(n / 2, y + n / 2, x);
				solve(n / 2, y + n / 2, x + n / 2);
				return;
			}
		}
	}
	cnt[color]++;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}

	solve(n, 0, 0);

	cout << cnt[0] << "\n";
	cout << cnt[1] << "\n";

	return 0;
}