#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> row[9];
set<int> col[9];
set<int> box[9];
int arr[9][9];
int fin;

void dfs(int y, int x) {
	if (x == 9) {
		x = 0;
		y++;
	}

	if (y == 9) {
		fin = 1;
		// print
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		return;
	}

	if (arr[y][x]) {
		dfs(y, x + 1);
		return;
	}
	
	for (int k = 1; k < 10; k++) {
		if (fin) return;
		if (row[y].find(k) != row[y].end()) continue;
		if (col[x].find(k) != col[x].end()) continue;
		if (box[(y / 3) * 3 + x / 3].find(k) != box[(y / 3) * 3 + x / 3].end()) continue;

		row[y].insert(k);
		col[x].insert(k);
		box[(y / 3) * 3 + x / 3].insert(k);
		arr[y][x] = k;
		dfs(y, x + 1);
		arr[y][x] = 0;
		box[(y / 3) * 3 + x / 3].erase(k);
		col[x].erase(k);
		row[y].erase(k);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	string s;
	for (int i = 0; i < 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = s[j] - '0';

			row[i].insert(arr[i][j]);
			col[j].insert(arr[i][j]);
			box[(i / 3) * 3 + j / 3].insert(arr[i][j]);
		}
	}

	dfs(0, 0);
}