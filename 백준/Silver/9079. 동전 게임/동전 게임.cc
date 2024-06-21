// bruteforce

#include <iostream>

using namespace std;

char coin[3][3];
int pat[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

int t, ans = 987654321;

bool chk() {
	char c = coin[0][0];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (coin[i][j] != c) return false;
		}
	
	return true;
}

void change(int idx) {
	for (int i : pat[idx]) {
		int y = i / 3;
		int x = i % 3;

		coin[y][x] = coin[y][x] == 'H' ? 'T' : 'H';
	}
}

void solve(int idx, int cnt) {
	// base case
	if (idx == 8) {
		if (chk()) {
			ans = min(cnt, ans);
		}
		return;
	}

	for (int i = 0; i < 2; i++) {
		solve(idx + 1, cnt + i);
		change(idx);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		ans = 987654321;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> coin[i][j];
			}
		}

		solve(0, 0);

		cout << (ans == 987654321 ? -1 : ans) << "\n";
	}
}