// bruteforce

#include <iostream>

using namespace std;

int col, fin;
int arr[19][19];
int dy[4] = {-1, 0, 1, 1};
int dx[4] = {1, 1, 1, 0};

bool chk(int y, int x, int dir, int cnt) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (cnt == 5) {
		if (ny < 0 || nx < 0 || ny >= 19 || nx >= 19) return true;
		if (arr[ny][nx] != col) return true;
		else return false;
	}

	if (ny < 0 || nx < 0 || ny >= 19 || nx >= 19)
		return false;

	if (arr[ny][nx] != col) return false;

	return chk(ny, nx, dir, cnt + 1);
}

void solve(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y - dy[i];
		int nx = x - dx[i];

		if (ny >= 0 && nx >= 0 && ny < 19 && nx < 19 && arr[ny][nx] == col) continue;

		if (chk(y, x, i, 1)) {
			fin = 1;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++) {
			col = arr[i][j];
			if (arr[i][j])
				solve(i, j);
			if (fin) {
				cout << col << "\n";
				cout << i + 1 << " " << j + 1 << "\n";
				return 0;
			}
		}

	cout << 0;

	return 0;
}

